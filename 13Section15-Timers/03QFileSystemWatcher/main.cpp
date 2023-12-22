/*
 * Why i would need to use a timer ?
 * File system watcher
 * Why
 * We want to know when sth changes
 * How
 * QFileSystemWatcher
 * what this does, as you pointed at a dir,
 * it monitors that dir for changes.
 * If sth changes, it lets you know.
 *
 * You've ever seen an app do that where it says,
 * please update the file, you update it, save and close
 * and then boom, the app magically knows the files ready.
 * This is exactly what we're doing here.
 *
 */

#include <QCoreApplication>
#include "watcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Watcher w;

    return a.exec();
}
