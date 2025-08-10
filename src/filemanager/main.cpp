#include <QApplication>
#include <QLabel>

int main() {
    QApplication app(argc, argv);
    
    QLabel *label = new QLabel("Hello, Arch Linux!");
    label->setWindowTitle("My First Qt App");
    label->resize(400, 300);
    label->show();
    
    return app.exec();
}