#include<iostream>
using namespace std;
/*
Inheritance:
student --> test [Done]
student --> sports[Done]
test --> result[Done]
sports --> result[Done]
*/
class Student{
protected:
int roll_no;
public:
void set_number(int a){
    roll_no=a;
}
void print_number(void){
    cout<<"Your roll no is"<<roll_no<<endl;
}
};

class Test : virtual public Student{
    protected:
    float maths, physics;
    public:
    void set_marks(float m1, float m2){
        maths=m1;
        physics=m2;
    }
    void print_marks(void){
        cout<< "Your result is here:"<<endl
        << "Maths:"<< maths<< endl
        << "Physics:"<<physics<<endl;
    }
};

class Sports:virtual public Student{
    protected:
    float score;
    public:
    void set_score(float sc){
        score=sc;
    }
    void print_score(void){
        cout<< "Your PT score is"<<score<<endl;
    }
};

class Result: public Test, public Sports{
    private:
    float total;
    public:
    void display(void){
        total= maths + physics + score;
        print_number();
        print_marks();
        print_score();
        cout<< "Your toal score is:"<<total<<endl;
    }
};

int main(){
    Result shakib;
    shakib.set_number(417);
    shakib.set_marks(95.0,94.0);
    shakib.set_score(8);
    shakib.display();
    return 0;
}