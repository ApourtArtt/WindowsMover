#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Windows.h>
#include <tlhelp32.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_MB_SET_clicked();

private:
    Ui::MainWindow *ui;
    static WINBOOL foreach_window(HWND hWnd, LPARAM lparam);
    static int x;
    static int y;
    static QString winName;
};
#endif // MAINWINDOW_H
