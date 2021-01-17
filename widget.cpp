#include "widget.h"
#include "ui_widget.h"

#include <QPalette>
#include <QLabel>
#include <QString>
#include <QStyle>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    struct EnumVal {
        int value;
        const char* name;
    };

    const EnumVal groups[] = {
        {QPalette::ColorGroup::Active, "Active"},
        {QPalette::ColorGroup::Disabled, "Disabled"},
        {QPalette::ColorGroup::Inactive, "Inactive"}
    };
    const EnumVal roles[] = {
        {QPalette::ColorRole::Window, "Window"},
        {QPalette::ColorRole::Background, "Background"},
        {QPalette::ColorRole::WindowText, "WindowText"},
        {QPalette::ColorRole::Foreground, "Foreground"},
        {QPalette::ColorRole::Base, "Base"},
        {QPalette::ColorRole::AlternateBase, "AlternateBase"},
        {QPalette::ColorRole::ToolTipBase, "TooltipBase"},
        {QPalette::ColorRole::ToolTipText, "TooltipText"},
        {QPalette::ColorRole::PlaceholderText, "PlaceholderText"},
        {QPalette::ColorRole::Text, "Text"},
        {QPalette::ColorRole::Button, "Button"},
        {QPalette::ColorRole::ButtonText, "ButtonText"},
        {QPalette::ColorRole::BrightText, "BrightText"},
        {QPalette::ColorRole::Light, "Light"},
        {QPalette::ColorRole::Midlight, "Midlight"},
        {QPalette::ColorRole::Dark, "Dark"},
        {QPalette::ColorRole::Mid, "Mid"},
        {QPalette::ColorRole::Shadow, "Shadow"},
        {QPalette::ColorRole::Highlight, "Hightlight"},
        {QPalette::ColorRole::HighlightedText, "HighlightedText"},
        {QPalette::ColorRole::Link, "Link"},
        {QPalette::ColorRole::LinkVisited, "LinkVisited"}
    };

    //const QPalette& palette = this->palette();
    const QPalette& palette = QApplication::style()->standardPalette();


    for (auto group : groups) {
        for (auto role : roles) {
            const auto color = palette.color((QPalette::ColorGroup)group.value, (QPalette::ColorRole)role.value);
            QLabel* label = new QLabel(this);

            const auto r = color.red();
            const auto g = color.green();
            const auto b = color.blue();
            QString style = QString("background-color: rgb(%1, %2, %3);").arg(r).arg(g).arg(b);
            QString text  =QString("%1, %2").arg(group.name).arg(role.name);

            label->setStyleSheet(style);
            label->setText(text);

            ui->verticalLayout->addWidget(label);

        }
    }

}

Widget::~Widget()
{
    delete ui;
}

