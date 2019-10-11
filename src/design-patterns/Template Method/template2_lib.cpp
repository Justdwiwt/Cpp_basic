#include <iostream>

using namespace std;

//����⿪����Ա
class Library {
public:
    //�ȶ� template method
    void Run() {
        Step1();

        if (Step2()) { //֧�ֱ仯 ==> �麯���Ķ�̬����
            Step3();
        }

        for (int i = 0; i < 4; i++) {
            Step4(); //֧�ֱ仯 ==> �麯���Ķ�̬����
        }

        Step5();
    }

    virtual ~Library() {}

protected:
    void Step1() { //�ȶ�
        cout << "Step1" << endl;
    }

    void Step3() { //�ȶ�
        cout << "Step3" << endl;
    }

    void Step5() {   //�ȶ�
        cout << "Step5" << endl;
    }

    virtual bool Step2() = 0; //�仯
    virtual void Step4() = 0; //�仯
};
