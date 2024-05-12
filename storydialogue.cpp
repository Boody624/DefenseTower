// storydialog.cpp
#include "storydialogue.h"

// storydialog.cpp
#include "game.h"
StoryDialog::StoryDialog(QWidget *parent, QStringList bgs, QStringList voices, QStringList speech) : QDialog(parent), currentIndex(0)
{
    QAudioOutput * bgoutput = new QAudioOutput();
    bgoutput->setVolume(30);
    bgsound->setAudioOutput(bgoutput);
    bgsound->setSource(QUrl(voices[0]));
    bgsound->setPlaybackRate(0.95);
    bgsound->play();
    // Initialize widgets
    setFixedSize(800, 600);
    this->bgs = bgs;
    this->voices = voices;
    // Set background image for the dialog
    backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(QPixmap(bgs[0]).scaled(size()));
    backgroundLabel->setFixedSize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(this);

    characterSpeechLabel = new QLabel(this);
    characterSpeechLabel->setFont(QFont("Arial", 16, QFont::Bold | QFont::TypeWriter)); // Set font
    characterSpeechLabel->setAlignment(Qt::AlignBottom | Qt::AlignLeft); // Align label

    nextButton = new QPushButton("Next", this);
    connect(nextButton, &QPushButton::clicked, this, &StoryDialog::nextSpeech);

    layout->addWidget(characterSpeechLabel);
    layout->addWidget(nextButton);

    // Set speech list
    speechList = speech;
    setCharacterSpeech(speechList.first()); // Display first speech
}

void StoryDialog::setCharacterSpeech(const QString &speech)
{
    // Set word wrap to true to automatically wrap text to fit within the label width
    characterSpeechLabel->setWordWrap(true);
    characterSpeechLabel->setText(speech);
}


void StoryDialog::nextSpeech()
{
    currentIndex++;
    if (currentIndex < speechList.size()) {
        setCharacterSpeech(speechList.at(currentIndex));
        backgroundLabel->setPixmap(QPixmap(bgs[currentIndex]).scaled(size()));
        backgroundLabel->setFixedSize(800, 600);

        if(bgsound->isPlaying())
        {
            bgsound->stop();
        }
        QAudioOutput * bgoutput = new QAudioOutput();
        bgoutput->setVolume(30);
        bgsound->setAudioOutput(bgoutput);
        bgsound->setSource(QUrl(voices[currentIndex]));
        bgsound->setPlaybackRate(0.95);
        if(currentIndex == 5){
            bgsound->setPlaybackRate(1.05);
        }
        bgsound->play();
    }
    else {
        // End of dialog, close the dialog
        if(bgsound->isPlaying())
        {
            bgsound->stop();
        }
        if(gameOver){
            exit(0);
        }
        if(bossBattle){
            game *g = new game();
            this->close();
            g->displayFinal();
            return;

        }
        game *g = new game();
        this->close();
        g->onDisplayLVL1();

    }
}






void StoryDialog::showNextCharacter()
{
    // Increment index and update speech label with next character
    currentIndex++;
    characterSpeechLabel->setText(currentSpeech.left(currentIndex));

    // Check if all characters have been displayed
    if (currentIndex >= currentSpeech.length()) {
        // Stop animation timer
        animationTimer->stop();
    }
}

void StoryDialog::startSpeechAnimation()
{
    // Initialize animation timer
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &StoryDialog::showNextCharacter);

    // Start animation timer
    animationTimer->start(100); // Adjust the interval as needed
}
