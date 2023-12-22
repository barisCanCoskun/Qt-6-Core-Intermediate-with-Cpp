/*
 * Process custom commands
 * why
 * Show we have the full system available
 * How
 * Windows - CMD
 * Linux - BASH
 * Mac - zsh
 */
#include <QCoreApplication>
#include "commander.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Commander cmd;
    cmd.action(QByteArray("pwd"));  // print working directory
    cmd.action(QByteArray("ls -l"));

    return a.exec();
}
















