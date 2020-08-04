#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QPushButton>
#include <QWidget>

class QLineEdit;

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
private slots:
    void OnClicked();

    void ClearButtonClicked();
    void BackspaceButtonClicked();
    void PointButtonClicked();

    void ModelButtonClicked();

    void EqualButtonClicked();
private:
    QLineEdit *display;
    int model = 0;
    QString first = "";
    QString second = "";

};

class Button : public QPushButton
{
Q_OBJECT

public:
    explicit Button(const QString &text);

    QSize sizeHint() const override;
};
#endif // CALCULATOR_H
