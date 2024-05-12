#include "optionsdialog.h"
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "game.h"
OptionsDialog::OptionsDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Options");
    setStyleSheet("background-color: #37474F; color: #ECEFF1;"); // Set background color and text color

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40); // Add margins to the layout

    // Volume slider
    // Volume slider
    QLabel *volumeLabel = new QLabel("Volume", this);
    volumeLabel->setStyleSheet("font-size: 18px;"); // Set font size

    volumeSlider = new QSlider(Qt::Horizontal, this);
    volumeSlider->setRange(0, 100);
    volumeSlider->setStyleSheet(
        "QSlider::groove:horizontal { background-color: #546E7A; height: 8px; border-radius: 4px; }"
        "QSlider::handle:horizontal { background-color: #03A9F4; width: 20px; border-radius: 10px; margin: -8px 0; }"
        ); // Set slider styles
    volumeSlider->setValue(currentVolume * 100);
    connect(volumeSlider, &QSlider::valueChanged, this, &OptionsDialog::onVolumeChanged);

    QHBoxLayout *volumeLayout = new QHBoxLayout;
    volumeLayout->addWidget(volumeLabel);
    volumeLayout->addWidget(volumeSlider);

    // Difficulty combo box
    QLabel *difficultyLabel = new QLabel("Difficulty", this);
    difficultyLabel->setStyleSheet("font-size: 18px;"); // Set font size
    difficultyComboBox = new QComboBox(this);
    difficultyComboBox->addItem("Easy");
    difficultyComboBox->addItem("Medium");
    difficultyComboBox->addItem("Hard");
    difficultyComboBox->setStyleSheet("QComboBox { background-color: #546E7A; color: #ECEFF1; border-radius: 5px; }"
                                      "QComboBox::item { padding: 8px; }"); // Set combo box styles
    connect(difficultyComboBox, QOverload<int>::of(&QComboBox::activated), this, &OptionsDialog::onDifficultyChanged);

    // About button
    aboutButton = new QPushButton("About", this);
    aboutButton->setStyleSheet("font-size: 16px; color: #ECEFF1; background-color: #03A9F4; padding: 10px 20px; border-radius: 5px;"); // Set button styles
    connect(aboutButton, &QPushButton::clicked, this, &OptionsDialog::toggleAboutText);

    // About text label
    aboutTextLabel = new QLabel("Welcome to the game!.\n\nThis game revolves around having a castle defended from the evil spirit. "
                                "\nWould you be able to do it?"
                                "\n\nCredits:"
                                "\n\nAbdelrahman Osama                      Omar Khalil                 Mohamed Yassin", this);
    aboutTextLabel->setStyleSheet("font-size: 14px; color: #ECEFF1;");
    aboutTextLabel->setWordWrap(true);
    aboutTextLabel->hide(); // Initially hide the about text

    // Add spacing between widgets
    layout->addSpacing(40);

    // Add widgets to layout
    layout->addWidget(volumeLabel);
    layout->addWidget(volumeSlider);
    layout->addWidget(difficultyLabel);
    layout->addWidget(difficultyComboBox);
    layout->addWidget(aboutButton);
    layout->addWidget(aboutTextLabel);

    // Set layout
    setLayout(layout);
    resize(600, 400);

}

void OptionsDialog::setVolume(int volume)
{
    volumeSlider->setValue(volume);
}

void OptionsDialog::setDifficulty(int difficulty)
{
    difficulty = game::difficulty;
}

void OptionsDialog::onVolumeChanged(int volume)
{
    emit volumeChanged(volume);
}

void OptionsDialog::onDifficultyChanged()
{
    if (difficultyComboBox->currentIndex() == 1) {
        game::difficulty = 1;
    } else if (difficultyComboBox->currentIndex() == 2) {
        game::difficulty = 2;
    } else {
        game::difficulty = 0;
    }
}

void OptionsDialog::toggleAboutText()
{
    if (aboutTextLabel->isHidden()) {
        aboutTextLabel->show();
        aboutButton->setText("Hide About"); // Change button text
    } else {
        aboutTextLabel->hide();
        aboutButton->setText("About"); // Change button text
    }
}
