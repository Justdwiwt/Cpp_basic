#include "template2_lib.cpp"
#include <iostream>

using namespace std;

//Ӧ�ó��򿪷���Ա
class Application : public Library {
protected:
    virtual bool Step2() {
        //... ������дʵ��
        cout << "override Step2" << endl;
        return true;
    }

    virtual void Step4() {
        //... ������дʵ��
        cout << "override Step4" << endl;
    }
};

int main() {
    Library *pLib = new Application();
    pLib->Run();

    delete pLib;
}
