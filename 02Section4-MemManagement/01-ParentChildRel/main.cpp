#include <QCoreApplication>
#include<QDebug>
#include"test.h"

Test *makeTree(){
    Test *root{new Test{nullptr, "Root"}};

    for (int p = 0; p < 3; ++p) {
        Test *parentObj{new Test{root, "Parent-" + QString::number(p)}};
        for (int c = 0; c < 2; ++c) {
            Test *childObj{new Test{parentObj,
            "Child-" + QString::number(p) + "- " + QString::number(c)}};
            for (int s = 0; s < 1; ++s) {
                Test *subObj{new Test{childObj,
                "Sub-" + QString::number(p) + "- " + QString::number(c) + "- " + QString::number(s)}};
                Q_UNUSED(subObj);
            }
        }
    }
    return root;
}

void printTree(Test *root, int level = 0){
    if(root->children().length() == 0) return;

    QString lead{"-"};
    lead.fill('-', level * 3);

    foreach (QObject *obj, root->children()){
        Test *child{qobject_cast<Test *>(obj)};
        if(!child) return;

        qInfo() << lead << child;
        printTree(child, level + 1);
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test *tree{makeTree()};
    printTree(tree, 0);

    delete tree;
    return a.exec();
}





