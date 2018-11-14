#include <QApplication>
#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>

#include <crossplatformicon.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // First we set the main theme. In this case, we'll set it to the system icon theme.
    CrossPlatformIcon::setThemeName( QIcon::themeName() );
    // Next we'll set a fallback icon theme
    CrossPlatformIcon::setFallbackThemeName("elementary");

    QVBoxLayout *l = new QVBoxLayout;
    QPushButton *b1 = new QPushButton("Button 1");
    QPushButton *b2 = new QPushButton("Button 2");
    b1->setIcon( CrossPlatformIcon::get("mail-reply-sender") );
    b2->setIcon( CrossPlatformIcon::get("cool-tux-penguin") );

    l->addWidget( b1 );
    l->addWidget( b2 );

    QFrame *f = new QFrame;
    f->setLayout(l);
    f->show();

    int status = a.exec();
    CrossPlatformIcon::destroyIconManager();
    return status;
}
