#include<iostream>
#include<ctime>

using namespace std;

const char genre[][40]={"Fiction","Non-Fiction","Slice of Life",
                        "Romance","Sci-fi","Horror","Drama","Action",
                        "Comedy","Crime and Mystery","Fantasy","Satire"};
const char topic[][40]={"Armageddon","Mirrors","Dad's Car",
                        "Graveyard","Typhoon","First Date","Elections",
                        "Holocaust","1896 Bengal","Cruise","Girl in the City","Neptune"};
const int SIZE=12;
static int count1[SIZE];
static int count2[SIZE];

class Input
{
    protected: 
               char* names;
    public: 
            void input()
            {
                names=new char[50];
                gets(names);
            }
};

class AllotTopic:virtual public Input
{
    protected:
                int pos;
    public: 
            void allot()
            {
                pos=rand()%SIZE;
                if(check(count1,pos))
                {
                    count1[pos]++;
                }
                else
                {
                    allot();
                }
            }
            bool check(int c[], int p)
            {
                for(int i=0;i<SIZE;i++)
                {
                    if(c[p]>c[i])
                    {
                        return false;
                    }
                }
                return true;
            }
};

class AllotGenre:virtual public Input
{
    protected:
                int pos;
    public: 
            void allot()
            {
                pos=rand()%SIZE;
                if(check(count2,pos))
                {
                    count2[pos]++;
                }
                else
                {
                    allot();
                }
            }
            bool check(int c[], int p)
            {
                for(int i=0;i<SIZE;i++)
                {
                    if(c[p]>c[i])
                    {
                        return false;
                    }
                }
                return true;
            }
};

class Display:public AllotTopic, public AllotGenre
{
    public:
            virtual void display()
            {
                AllotTopic::allot();
                AllotGenre::allot();
                cout<<names<<"-"<<topic[AllotTopic::pos]<<" and "<<genre[AllotGenre::pos]<<endl;
            }
};

int main()
{
    srand(time(0));
    cout<<"Enter the number of participants : ";
    int n;
    cin>>n;
    Display obj[n];
    getchar();
    cout<<"Enter the names :"<<endl;
    for(int i=0;i<n;i++)
    {
        obj[i].input();
    }
    cout<<"***Alloted Topics and Genres***"<<endl;
    for(int i=0;i<n;i++)
    {
        obj[i].display();
    }
}