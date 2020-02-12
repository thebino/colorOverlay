#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(640, 480);
    setWindowTitle(tr("colorOverlay"));
    setAcceptDrops(true);

    QLabel * center = new QLabel(tr("Place your files here!"));
    center->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    setCentralWidget(center);
}

MainWindow::~MainWindow()
{
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
        painter.fillRect(resultImage.rect(), QColor(252, 98, 247, 178));
        painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
        painter.drawImage(0, 0, sourceImage);

        painter.end();

        resultImage.save(fileName);
    }
}
