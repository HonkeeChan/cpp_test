#include <iostream>
#include <memory>

using namespace std;

class TestB;
class TestA
{
public:
    TestA()
    {
        std::cout << "TestA()" << std::endl;
    }
    void ReferTestB(std::shared_ptr<TestB> test_ptr)
    {
        m_TestB_Ptr = test_ptr;
    }
    ~TestA()
    {
        std::cout << "~TestA()" << std::endl;
    }
private:
    std::shared_ptr<TestB> m_TestB_Ptr; //TestB的智能指针
}; 

class TestB :  public TestA
{
public:
    TestB()
    {
        std::cout << "TestB()" << std::endl;
    }

    void ReferTestB(std::shared_ptr<TestA> test_ptr)
    {
        m_TestA_Ptr = test_ptr;
    }
    ~TestB()
    {
        std::cout << "~TestB()" << std::endl;
    }
    std::shared_ptr<TestA> m_TestA_Ptr; //TestA的智能指针
};

int main(){
    cout << "********test shared ptr*********" << endl;
    shared_ptr<TestA> pta = make_shared<TestA>();
    //shared_ptr<TestB> ptb = 
    pta = make_shared<TestB>();
    cout << "after assigned value to pta";
    cout << "********end*********" << endl;
    return 0;
}