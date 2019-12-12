#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    int age, standard;
    string firstName, lastName;

    public:
        void set_age (int customAge){
            age = customAge;
        }

        int get_age (){
            return age;
        }

        void set_first_name(string customFirstName){
            firstName = customFirstName;
        }

        string get_first_name (){
            return firstName;
        }   

        void set_last_name (string customLastName){
            lastName = customLastName;
        }

        string get_last_name(){
            return lastName;
        }

        void set_standard (int customStandard){
            standard = customStandard;
        }

        int get_standard(){
            return standard;
        }

        string to_string(){
            int age = get_age();
            string firstName = get_first_name();
            string lastName = get_last_name();
            int standard = get_standard();

            stringstream ss;

            ss << age << "," << firstName << "," << lastName << "," << standard << endl;
            return ss.str();
        }

};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}


