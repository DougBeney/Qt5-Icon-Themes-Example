#include <QApplication>
#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QIcon::setFallbackSearchPaths(QIcon::fallbackSearchPaths() << ":custom-icons");

    // Create a layout and two buttons
    QVBoxLayout *l = new QVBoxLayout;
    QPushButton *b1 = new QPushButton("Button 1");
    QPushButton *b2 = new QPushButton("Button 2");
    l->addWidget( b1 );
    l->addWidget( b2 );

    // OPTIONAL: Set your own icon pack. By default, Qt will search in :icons/
    QIcon::setThemeName( "zafiro" );

    // Set icons from theme
    b1->setIcon( QIcon::fromTheme("folder-alt") ); // Most Linux icon packs will have a "battery" icon.
    b2->setIcon( QIcon::fromTheme("open-app-library") ); // If this does not exist in icon pack (It won't), it will search :custom-icons/

    // Create a frame that uses layout and show widgets
    QFrame *f = new QFrame;
    f->setLayout(l);
    f->show();

    return a.exec();
}
