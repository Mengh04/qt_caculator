#include "calculator.h"
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

QSize Button::sizeHint() const
{
    QSize size = QPushButton::sizeHint();
    size.rwidth() -= 20;
    size.rheight() = size.width();
    return size;
}
Button::Button(const QString &text)
{
    setText(text);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);//设置大小方案
}



Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    /***************************************/
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);
    /***************************************/
    /**********************************************/
    Button *oneButton = new Button("1");
    Button *twoButton = new Button("2");
    Button *threeButton = new Button("3");
    Button *fourButton = new Button("4");
    Button *fiveButton = new Button("5");
    Button *sixButton = new Button("6");
    Button *sevenButton = new Button("7");
    Button *eightButton = new Button("8");
    Button *nineButton = new Button("9");
    Button *zeroButton = new Button("0");

    Button *pointButton = new Button(".");
    Button *plusButton = new Button("+");
    Button *minusButton = new Button("-");
    Button *multiplyButton = new Button("*");
    Button *divideButton = new Button("/");
    Button *equalButton = new Button("=");

    Button *backspaceButton = new Button("B");
    Button *clearButton = new Button("C");
    /**********************************************/
    QGridLayout *mainlayout = new QGridLayout;
    mainlayout->setSizeConstraint(QLayout::SetFixedSize);

    mainlayout->addWidget(display,0,0,1,5);
    mainlayout->addWidget(oneButton,1,0);
    mainlayout->addWidget(twoButton,1,1);
    mainlayout->addWidget(threeButton,1,2);
    mainlayout->addWidget(fourButton,2,0);
    mainlayout->addWidget(fiveButton,2,1);
    mainlayout->addWidget(sixButton,2,2);
    mainlayout->addWidget(sevenButton,3,0);
    mainlayout->addWidget(eightButton,3,1);
    mainlayout->addWidget(nineButton,3,2);
    mainlayout->addWidget(zeroButton,4,0);

    mainlayout->addWidget(plusButton,1,3);
    mainlayout->addWidget(minusButton,2,3);
    mainlayout->addWidget(multiplyButton,3,3);
    mainlayout->addWidget(divideButton,4,3);
    mainlayout->addWidget(pointButton,4,1);
    mainlayout->addWidget(equalButton,4,2);

    mainlayout->addWidget(backspaceButton,1,4,2,1);
    mainlayout->addWidget(clearButton,3,4,2,1);

    setLayout(mainlayout);
    /****************************************************************/
        connect(oneButton,SIGNAL(clicked()),this,SLOT(OnClicked()));
        connect(twoButton,SIGNAL(clicked()),this,SLOT(OnClicked()));
        connect(threeButton,SIGNAL(clicked()),this,SLOT(OnClicked()));
        connect(fourButton,SIGNAL(clicked()),this,SLOT(OnClicked()));
        connect(fiveButton,SIGNAL(clicked()),this,SLOT(OnClicked()));
        connect(sixButton,SIGNAL(clicked()),this,SLOT(OnClicked()));
        connect(sevenButton,SIGNAL(clicked()),this,SLOT(OnClicked()));
        connect(eightButton,SIGNAL(clicked()),this,SLOT(OnClicked()));
        connect(nineButton,SIGNAL(clicked()),this,SLOT(OnClicked()));
        connect(zeroButton,SIGNAL(clicked()),this,SLOT(OnClicked()));

        connect(plusButton,SIGNAL(clicked()),this,SLOT(ModelButtonClicked()));
        connect(minusButton,SIGNAL(clicked()),this,SLOT(ModelButtonClicked()));
        connect(multiplyButton,SIGNAL(clicked()),this,SLOT(ModelButtonClicked()));
        connect(divideButton,SIGNAL(clicked()),this,SLOT(ModelButtonClicked()));
        connect(equalButton,SIGNAL(clicked()),this,SLOT(EqualButtonClicked()));

        connect(clearButton,SIGNAL(clicked()),this,SLOT(ClearButtonClicked()));
        connect(backspaceButton,SIGNAL(clicked()),this,SLOT(BackspaceButtonClicked()));
        connect(pointButton,SIGNAL(clicked()),this,SLOT(PointButtonClicked()));
    /***************************************************************/
}
void Calculator::PointButtonClicked()
{
    if (!display->text().contains("."))
    {
        display->setText(display->text()+".");
    }
}
void Calculator::OnClicked()
{
    Button *clickButton = qobject_cast<Button *>(sender());
    QString text = display->text();
    if (text=="0" || text == "+" || text == "-" || text =="*" || text == "/")
    {
        display->setText("");
    }
    display->setText(display->text() + clickButton->text());
}

void Calculator::ClearButtonClicked()
{
    display->setText("0");
    first = "";
    second = "";
    model = 0;
}

void Calculator::BackspaceButtonClicked()
{
    QString text = display->text();
    text.chop(1);
    display->setText(text);
    if (display->text() == "")
    {
        display->setText("0");
    }
}
void Calculator::ModelButtonClicked()
{
    Button *modelButton = qobject_cast<Button *>(sender());
    QString text = modelButton->text();

    if (display->text() != "0" || first != "")
    {
        if (text == "+")
        {
            model = 1;
        }
        else if (text == "-")
        {
            model = 2;
        }
        else if (text == "*")
        {
            model = 3;
        }
        else if (text == "/")
        {
            model = 4;
        }

        first = display->text();
        display->setText(text);
    }

}
void Calculator::EqualButtonClicked()
{
    second = display->text();
    switch (model)
    {
    case 1 :
        display->setText(QString::number(first.toDouble() + second.toDouble()));
        break;
    case 2:
        display->setText(QString::number(first.toDouble() - second.toDouble()));
        break;
    case 3:
        display->setText(QString::number(first.toDouble() * second.toDouble()));
        break;
    case 4:
        display->setText(QString::number(first.toDouble() / second.toDouble()));
        break;
    }
    first = display->text();
    model = 0;

}

Calculator::~Calculator()
{
}

