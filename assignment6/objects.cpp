#include <iostream>
using namespace std;
/*
        USING DEFAULT CONSTRUCTORS !
  ==========================================
 
 class Base {
     // sub-classes will inherit all from the protected, & public spaces.
     // sub-classes will NOT inherit from the private space,
     // which is the default for classes
     int *const aVar = new int {44};
     // we can only access aVar w/in the private space to be able to use it outside the
     // private we must make a function that will do this for us !
     protected:
     // pointers defined like the folling "type *const var_name = new type {};"
     // allows values to change in the same memory address, but the address of the
     // asigned point cannot change !
         int *const myX = new int {7};
         int *const myY = new int {9};
     public:
         // we should make a public function that return the value of the protected myX & myY
         int protecX() { return *myX;}
         int protecY() { return *myY;}
     
         // function to get the value of aVar which is private !
         int priVar() { return *aVar;}
         // any derived sub-class will also inherit this function ! So in turn all of our
         // sub-classes will have access to the value of aVar !
     
         // lets create some setters for setting the value of our variables !
         void setMyX (int num) {
             *myX = num;
         }
         void setMyY (int num) {
             *myY = num;
         }
         void setPriVar (int num) {
             *aVar = num;
         }
         // public variables !
         int *const x = new int {5}; // Base's x
         int *const y = new int {2}; // Base's y


 };

 class Derived : public Base {
 
    // Implement a derived class that should define a property that has the same
    // name as a private property of the parent class
  
     int *const aVar = new int {12};
     // this Derived class WILL inherit JUST THE protected, & public spaces
     // from the Base class
     protected:
         int *const myX = new int {4};
         int *const myY = new int {1};
     public:
         // functions that get the value of the inherited myX, & myY
         int gety() { return *Base::myY;}
         int getx() { return *Base::myX;}
         
         // functions that get the value of myX, & myY
         int protecX() { return *myX;}
         int protecY() { return *myY;}

         // functions to get the value of aVar which is private !
         int priVar() { return *aVar;}
         int basePriVar() { return Base::priVar();}
     
         // functions to get the inherited x & y that we got from Base !
         int getInheritPubX() { return *Base::x;}
         int getInheritPubY() { return *Base::y;}
     
         // We now need to define setter to be able to dynamically set our variables !
         void setMyX (int num) {
             *myX = num;
         }
         void setMyY (int num) {
             *myY = num;
         }
         void setPrivVar (int num) {
             *aVar = num;
         }
     
         int *const x = new int {3}; // Derived's x
         int *const y = new int {8}; // Derived's y
     

 };

 int main() {
     Base b;
     Derived d;
     
     // public inheritance
     cout << "b's x is: " << *(b.x) << " " << endl; // b's x is 5
     cout << "d's x is: " << *(d.x) << " " << endl;
     cout << "d's inherited x is: " << d.getInheritPubX() <<  " " << endl; // x is 5
     cout << endl;
     
     cout << "b's y is: " << *b.y << " " << endl; // b's y is 2
     cout << "d's y is: " << *d.y << " " << endl; // b's y is 8
     cout << "d's inherited y is: " << d.getInheritPubY() << " " << endl; // y is 2
     cout << endl;
     
     // protected inheritance
     //cout << "b's protected x is: " << *b.myX << endl; // cannot access myX since it is
                                                         // protected !
     //cout << "b's protected y is: " << *b.myY << endl; // cannot access myY since it is
                                                         // protected !
     //cout << "d's protected x is: " << *d.myX << endl; // cannot access myX since it is
                                                         // protected !
     //cout << "b's protected x is: " << *b.myX << endl; // cannot access myX since it is
                                                         // protected !
     cout << "b's protected myX is: " << b.protecX() << endl; // b's protected x is 7
     cout << "d's protected myX is: " << d.protecX() << endl; // d's protected x is 4
     // d also has a protecX function that was inherited from base !
     //cout << "d's inherited protected x is: " << *d.Base::myX << endl; // Will not work
                         // myX is private, lets implement a function
     cout << "d's inherited protected myX is: " << d.getx() << endl; // x is 7
     cout << endl;
     
     cout << "b's protected myY is: " << b.protecY() << endl; // y is 9
     cout << "d's protected myY is: " << d.protecY() << endl; // y is 1
     cout << "d's inherited myY is: " << d.gety() << endl; // y is 9
     cout << endl;
     
     //cout << "b's private aVar is: " << b.aVar << endl; // cannot access aVar since its
                                                         // private !
     cout << "b's private aVar is: " << b.priVar() << endl;
     cout << "d's private aVar is: " << d.priVar() << endl;
     cout << "d's inherited private aVar is: " << d.basePriVar() << endl;
     cout << endl;
     
     // making use of all the setter functions to change the values of all variables !
     b.setMyX(15); // b's myX is now set to the value of 15
     *b.x = 17;
     b.setMyY(200); // b's myY is now set to the value of 200
     b.setPriVar(1); // b's private aVar is now set to 1
     d.setMyX(55); // d's private myX is now set to the value of 55
     *d.x = 25;
     d.setMyY(40); //d's private myY is now set to the value of 40
     d.setPriVar(80); // d's privat aVar is now set to 80
     
     // public inheritence
     cout << "b's x is: " << *(b.x) << " " << endl; // b's x is 17
     cout << "d's x is: " << *(d.x) << " " << endl; // d's x is 25
 
 //       d's inherited x will still be 5, even though we just changed the x in Base.
 //         when d inherits the Base class we're just "coping" all the protected, and public
 //         code into our derived class.
 
     cout << "d's inherited x is: " << d.getInheritPubX() <<  " " << endl; // x is 5
     cout << endl;
     
     cout << "b's y is: " << *b.y << " " << endl; // b's y is 2
     cout << "d's y is: " << *d.y << " " << endl; // b's y is 8
     cout << "d's inherited y is: " << d.getInheritPubY() << " " << endl; // y is 2
     cout << endl;
     
     // protected inheritence
     cout << "b's protected myX is: " << b.protecX() << endl; // b's protected x is 7
     cout << "d's protected myX is: " << d.protecX() << endl; // d's protected x is 4
     cout << "d's inherited protected myX is: " << d.getx() << endl; // x is 7
     cout << endl;
     
     cout << "b's protected myY is: " << b.protecY() << endl; // y is 9
     cout << "d's protected myY is: " << d.protecY() << endl; // y is 1
     cout << "d's inherited myY is: " << d.gety() << endl; // y is 9
     cout << endl;
     
     //cout << "b's private aVar is: " << b.aVar << endl; // cannot access aVar since its
                                                         // private !
     cout << "b's private aVar is: " << b.priVar() << endl;
     cout << "d's private aVar is: " << d.priVar() << endl;
     cout << "d's inherited private aVar is: " << d.basePriVar() << endl;
 }
 
 */

class Base {
    // sub-classes will inherit all from the protected, & public spaces.
    // sub-classes will NOT inherit from the private space,
    // which is the default for classes
    int * aVar = new int {};
    // we can only access aVar w/in the private space to be able to use it outside the
    // private we must make a function that will do this for us !
    protected:
    // pointers defined like the folling "type *const var_name = new type {};"
    // allows values to change in the same memory address, but the address of the
    // asigned point cannot change !
        int * myX = new int {};
        int * myY = new int {};
    public:
        
        // we should make a public function that return the value of the protected myX & myY
        int protecX() { return *myX;}
        int protecY() { return *myY;}
    
        // function to get the value of aVar which is private !
        int priVar() { return *aVar;}
        // any derived sub-class will also inherit this function ! So in turn all of our
        // sub-classes will have access to the value of aVar !
    
        // lets create some setters for setting the value of our variables !
        void setMyX (int num) {
            *myX = num;
        }
        void setMyY (int num) {
            *myY = num;
        }
        void setPriVar (int num) {
            *aVar = num;
        }
        // public variables !
        int * x = new int {}; // Base's x
        int * y = new int {}; // Base's y

        // Base class constructors !
        Base (int x1, int y1) {
            // if no 3rd parameter is provided then the private variable aVar will be set
            // to the
            // value of myX + myY
            *myX = x1;
            *myY = y1;
            *x = *myX + 1;
            *y = *myY + 1;
            *aVar = *myX + *myY;
        }
        Base (int x1, int y1, int randomNum) {
            *myX = x1;
            *myY = y1;
            *x = *myX + 1;
            *y = *myY + 1;
            *aVar = randomNum;
        }
        ~Base() {
            delete x;
            x = nullptr;
            delete y;
            y = nullptr;
            delete myX;
            myX = nullptr;
            delete myY;
            myY = nullptr;
            delete aVar;
            aVar = nullptr;
        }

};

class Derived : public Base {
/*
    Implement a derived class that should define a property that has the same
    name as a private property of the parent class
 */
    int * aVar = new int {};
    // this Derived class WILL inherit JUST THE protected, & public spaces
    // from the Base class
    protected:
        int * myX = new int {};
        int * myY = new int {};
    public:
        // functions that get the value of the inherited myX, & myY
        int gety() { return *Base::myY;}
        int getx() { return *Base::myX;}
        
        // functions that get the value of myX, & myY
        int protecX() { return *myX;}
        int protecY() { return *myY;}

        // functions to get the value of aVar which is private !
        int priVar() { return *aVar;}

        // functions to get the inherited x & y that we got from Base !
        int getInheritPubX() { return *Base::x;}
        int getInheritPubY() { return *Base::y;}
    
        // We now need to define setter to be able to dynamically set our variables !
        void setMyX (int num) {
            *myX = num;
        }
        void setMyY (int num) {
            *myY = num;
        }
        void setPrivVar (int num) {
            *aVar = num;
        }
    
        int * x = new int {}; // Derived's x
        int * y = new int {}; // Derived's y
    
        // Derived class constructors !
        Derived (int x1, int y1) : Base (x1, y1) {
        /*
            If no 3rd parameter is given then public x , & public y will be set to x += 2
            & y += 2. Also the private variable aVar is set to myX + myY
            myX = x & myY = y
         */
            *myX = x1;
            *myY = y1;
            *x = *myX + 2;
            *y = *myY + 2;
            *aVar = *myX + *myY;
        }
        Derived (int x1, int y1, int randomNum) : Base (x1, y1, randomNum) {
            /*
                If no, pubX && pubY are given then public x += 2 & y += 2
                myX = x, myY = y, & the private variable aVar is = random number !
             */
            *myX = x1;
            *myY = y1;
            *x += 2;
            *y += 2;
            *aVar = randomNum;
        }
        ~Derived() {
            delete x; x = nullptr;
            delete y; y = nullptr;
            delete myX; myX = nullptr;
            delete myY; myY = nullptr;
            delete aVar; aVar = nullptr;
        }
};

class Cousin : public Derived{
    // Cousin is inheriting from the Derived class which is in turn inheriting
    // from the Base class. We are inheriting 2 classes in total !
    int * aVar = new int {};
    
    protected:
        int * myX = new int {};
        int * myY = new int {};
    
    public:
        int * x = new int {};
        int * y = new int {};

        // functions that get the value of the inherited Derived myX, & myY
        int getDerY() { return *Cousin::Derived::myY;}
        int getDerX() { return *Cousin::Derived::myX;}
        
        // functions that get the value of the inherited Base myX & myY !
        int getBaseX() { return *Cousin::Base::myX;}
        int getBaseY() { return *Cousin::Base::myY;}
        
        // functions that get the value of myX, & myY
        int protecX() { return *myX;}
        int protecY() { return *myY;}
        // functions to get the value of aVar which is private !
        int priVar() { return *aVar;}
     
        // functions to get the inherited x & y that we got from Base !
        int getInheritPubX() { return 0;}
        int getInheritPubY() { return 0;}
     
        // We now need to define setter to be able to dynamically set our variables !
        void setMyX (int num) {
            *myX = num;
        }
        void setMyY (int num) {
            *myY = num;
        }
        void setPrivVar (int num) {
            *aVar = num;
        }
     

         // Derived class constructors !
        Cousin (int x1, int y1) : Derived (x1, y1) {
        /*
             If no 3rd parameter is given then public x , & public y will be set to x += 2
             & y += 2. Also the private variable aVar is set to myX + myY
             myX = x & myY = y
        */
            *myX = x1;
            *myY = y1;
            *x = *myX + 3;
            *y = *myY + 3;
            *aVar = *myX + *myY + 1;
        }
        Cousin (int x1, int y1, int randomNum) : Derived (x1, y1, randomNum) {
        /*
            If no, pubX && pubY are given then public x += 2 & y += 2
            myX = x, myY = y, & the private variable aVar is = randomNum !
        */
            *myX = x1;
            *myY = y1;
            *x += 2;
            *y += 2;
            *aVar = randomNum;
        }
        ~Cousin() {
            delete x; x = nullptr;
            delete y; y = nullptr;
            delete myX; myX = nullptr;
            delete myY; myY = nullptr;
            delete aVar; aVar = nullptr;
        }
};

int main() {
    Base *b = new Base(1,2);
    Derived *d = new Derived(4,5);
    Cousin *c = new Cousin(7,8);
    // public inheritance
    cout << "b's x is: " << *b -> x << endl; // b's x is 2
    cout << "d's x is: " << *d -> x << endl; // d's x is 6
    cout << "d's inherited x is: " << d->getInheritPubX() << endl; // x is 5
    // because when we make a derived instance we're passing in 4, & 5 to our Deriverd
    // constructor & in turn it is passing 4 & 5 into the Base construction as well, so
    // for Base that d is inheriting myX = 4, so in turn x = myX + 1 so 5
    // myY = 5, in turn y = myY + 1 = 6
    cout << "c's x is: " << *c -> x << endl; // x is 10 we're passing 7 then + 3 so 10
    cout << "c's inherited Derived x is: " << *c -> Derived::x << endl; // x is 9
    // in c's constructor we called it with (7 & 8) our Derived myX is 7 and x = myX + 2
    // so x = 9
    cout << "c's inherited Base x is: " << *c -> Base::x << endl; // x is 8 like previously
    // mentioned when c's constructor is called it also calls Base's constructor with the
    // same passed args of (7,8) and since in Base myX = 7 and x = myX + 1, so x = 8
    cout << endl;
    
    cout << "b's y is: " << *b -> y << endl; // b's y is 3
    cout << "d's y is: " << *d -> y << endl; // b's y is 7
    cout << "d's inherited y is: " << d -> getInheritPubY() << endl; // y is 2
    cout << "d's inherited x is: " << d -> getInheritPubX() << endl; // x is 5
    // because when we make a derived instance we're passing in 4, & 5 to our Deriverd
    // constructor & in turn it is passing 4 & 5 into the Base construction as well, so
    // we for Base myX = 5, so in turn x = myX + 1 so 6
    cout << "c's y is: " << *c -> y << endl; // y is 8
    cout << "c's inherited Derived y is: " << *c -> Derived::y << endl; //c's Derived y = 10
    cout << "c's inherited Base y is: " << *c -> Base::y << endl; // c's Base y = 9
    cout << endl;
    
    // protected inheritance
    //cout << "b's protected x is: " << *b.myX << endl; // cannot access myX since it is
                                                        // protected !
    //cout << "b's protected y is: " << *b.myY << endl; // cannot access myY since it is
                                                        // protected !
    //cout << "d's protected x is: " << *d.myX << endl; // cannot access myX since it is
                                                        // protected !
    //cout << "b's protected x is: " << *b.myX << endl; // cannot access myX since it is
                                                        // protected !
    cout << "b's protected myX is: " << b -> protecX() << endl; // b's protected x is 7
    cout << "d's protected myX is: " << d -> protecX() << endl; // d's protected x is 4
    // d also has a protecX function that was inherited from base !
    //cout << "d's inherited protected x is: " << *d.Base::myX << endl; // Will not work
                        // myX is private, lets implement a function
    cout << "d's inherited protected myX is: " << d -> getx() << endl; // x is 7
    cout << "c's protected myX is: " << c -> protecX() << endl; // x is 7
    cout << "c's inherited protected Derived myX is: " << c -> Derived::protecX() << endl;
    // c's constructor will call the Derived constructor with the passed args, so Derived
    // will get constructed using the same args
    cout << "c's inherited protected Base myX is: " << c -> Base::protecX() << endl;
    cout << endl;
    
    cout << "b's protected myY is: " << b -> protecY() << endl; // y is 9
    cout << "d's protected myY is: " << d -> protecY() << endl; // y is 1
    cout << "d's inherited myY is: " << d -> gety() << endl; // y is 9
    cout << "c's protected myY is: " << c -> protecY() << endl; // y is 8
    cout << "c's inherited protected Derived myY is: " << c->Derived::protecY()
        << endl; // y is 8
    cout << "c's inherited protected Base myY is: " << c -> Base::protecY()
        << endl; // y is 8
    cout << endl;
    
    //cout << "b's private aVar is: " << b.aVar << endl; // cannot access aVar since its
                                                        // private !
    cout << "b's private aVar is: " << b -> priVar() << endl; // aVar = 3
    cout << "d's private aVar is: " << d -> priVar() << endl; // aVar = 9
    cout << "d's inherited private aVar is: " << d -> priVar() << endl; // aVar = 9
    cout << "c's private aVar is: " << c -> priVar() << endl; // aVar = 16
    cout << "c's inherited Derived private aVar is: " << c -> Derived::priVar() << endl;
    // aVar = 15
    cout << "c's inherited Base private aVar is: " << c -> Base::priVar() << endl;
    // aVar = 15
    cout << endl;
    
    // making use of all the setter functions to change the values of all variables !
    b -> setMyX(15); // b's myX is now set to the value of 15
    *b -> x = 17;
    *b -> y = 1;
    b -> setMyY(200); // b's myY is now set to the value of 200
    b -> setPriVar(1); // b's private aVar is now set to 1
    d -> setMyX(55); // d's private myX is now set to the value of 55
    *d -> x = 25;
    *d -> y = 10;
    d -> setMyY(40); //d's private myY is now set to the value of 40
    d -> setPriVar(80); // d's privat aVar is now set to 80
    c -> setMyX(66); // c's myX is now 66
    *c -> x = 3;
    c -> setMyY(19);
    *c -> y = 9;
    c -> setPrivVar(88);
    
    // public inheritence
    cout << "b's x is: " << *(b -> x) << endl; // b's x is 17
    cout << "d's x is: " << *(d -> x) << endl; // d's x is 25
    /*
         d's inherited x will still be 5, even though we just changed the x in Base.
         when d inherits the Base class we're just "coping" all the protected, and public
         code into our derived class.
     */
    cout << "d's inherited x is: " << d -> getInheritPubX() << endl; // x is 5
    cout << "c's x is: " << *c -> x << endl; // x is 3
    cout << "c's inherited Derived x is: " << *c -> Derived::x << endl; // x is 9
    cout << "c's inherited Base x is: " << *c -> Base::x << endl; // x is 8
    cout << endl;
    
    cout << "b's y is: " << *b -> y << endl; // b's y is 1
    cout << "d's y is: " << *d -> y << endl; // d's y is 10
    cout << "d's inherited y is: " << d -> getInheritPubY() << endl; // y is 6
    cout << "c's y is: " << *c -> y << endl; // y is 9
    cout << "c's inherited Derived y is: " << *c -> Derived::y << endl; //c's Derived y = 10
    cout << "c's inherited Base y is: " << *c -> Base::y << endl; // c's Base y = 9
    cout << endl;
    
    // protected inheritence
    cout << "b's protected myX is: " << b -> protecX() << endl; // b's protected x is 15
    cout << "d's protected myX is: " << d -> protecX() << endl; // d's protected x is 55
    cout << "d's inherited protected myX is: " << d -> getx() << endl; // x is 4
    cout << "c's protected myX is: " << c -> protecX() << endl; // x is 66
    cout << "c's inherited protected Derived myX is: " << c -> Derived::protecX() << endl;
    // c's inherited protected myX is 7
    cout << "c's inherited protected Base myX is: " << c -> Base::protecX() << endl;
    // c's inherited protected myY is 7
    cout << endl;
    
    cout << "b's protected myY is: " << b ->protecY() << endl; // y is 200
    cout << "d's protected myY is: " << d -> protecY() << endl; // y is 40
    cout << "d's inherited myY is: " << d -> gety() << endl; // y is 5
    cout << "c's protected myY is: " << c -> protecY() << endl; // y is 19
    cout << "c's inherited protected Derived myY is: " << c->Derived::protecY()
        << endl; // y is 8
    cout << "c's inherited protected Base myY is: " << c -> Base::protecY()
        << endl; // y is 8
    cout << endl;
    
    //cout << "b's private aVar is: " << b.aVar << endl; // cannot access aVar since its
                                                        // private !
    cout << "b's private aVar is: " << b -> priVar() << endl; // b's aVar is 1
    cout << "d's private aVar is: " << d -> priVar() << endl; // d's aVar is 9
    cout << "d's inherited private aVar is: " << d -> Base::priVar() << endl; // aVar is 80
    cout << "c's private aVar is: " << c -> priVar() << endl; // aVar = 88
    cout << "c's inherited Derived private aVar is: " << c -> Derived::priVar() << endl;
    // aVar = 15
    cout << "c's inherited Base private aVar is: " << c -> Base::priVar() << endl;
    // aVar = 15
    cout << endl;

    delete b;
    delete (d);
    delete c;
    // cout << "b's public x is: " << *b -> x << endl; // ERROR cannot access null address
    // cout << "d's public x is: " << *d -> x << endl; // cannot access null address 0x0
    // cout << "c's public x is: " << *c -> x << endl;
    return 0;
}
