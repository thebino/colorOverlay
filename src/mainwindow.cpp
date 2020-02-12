#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    *color = QColor(252, 98, 247, 178);
    setupUi(this);
    connect(button, SIGNAL(clicked()), this, SLOT(selectColor()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUi(QMainWindow *parent)
{
    central = new QWidget{parent};
    layout = new QGridLayout{central};
    label = new QLabel{"Place your files here!"};

    button = new QPushButton(this);
    button->setText("Select your color");

    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(button, 0, 0);
    layout->addWidget(label, 1, 0);
    parent->setCentralWidget(central);
    parent->setWindowTitle(tr("colorOverlay"));
    parent->setMinimumSize(640, 400);
    parent->setAcceptDrops(true);

    QString qss = QString("background-color: %1").arg(color->name());
    button->setStyleSheet(qss);
}

void MainWindow::selectColor()
{
    qDebug() << "selectColor()...";
    *color = QColorDialog::getColor(*color,this);
    
    if (color->isValid()) {
        color->setAlpha(178);
        QString qss = QString("background-color: %1").arg(color->name());
        button->setStyleSheet(qss);
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls()) {
        QString fileName = url.toLocalFile();        
        QImage sourceImage = QImage();
        bool loadSuccessfully = sourceImage.load(fileName);

        if(!loadSuccessfully) {
            QMessageBox::warning(NULL,tr("Invalid File"),tr("Droped file is invalid!"));
        }

        QSize resultSize(sourceImage.width(), sourceImage.height());

        QImage resultImage = QImage(resultSize, QImage::Format_ARGB32);
        
        QPainter painter(&resultImage);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.fillRect(resultImage.rect(), *color);
        painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
        painter.drawImage(0, 0, sourceImage);

        painter.end();

        resultImage.save(fileName);
    }
}
