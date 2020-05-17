//v2.0 does not actually use stage 3

#include<iostream>
#include<math.h>
#include<ctime>
#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<cstdlib>
//#include<dos.h>
//#include<windows.h>
//#include <chrono>

#include <time.h>
#include <vector>
#include <fstream>

#include<random>

using namespace std;

//using namespace std::chrono;

class SudokuGen
{

int limit1,limit2;

int mat[10][10];

int dummy[10][10];

int hashtable[9];

//char puzzmat[10][10];
int puzzmat[10][10];

int diffi;

//int tempp;

//int i,j;
int universalcount;
//int counter2;

public:

int r;

int tempp;
int tempp2;
int counter2;
int flag;

int collectorarray[10];
int collectorarrayrow[10];    //The numbers present will go at their respective indexes in this array.
int collectorarraycol[10];
int eligiblenos[10];       //The same will not happen for this array. The few eligible nos. will be stored at the initial positions in this array.
int toteligiblenos;

    SudokuGen()
    {
        //srand(time(0));
        //srand(GetTickCount());
        counter2=0;
        flag=0;

        tempp=0;
        tempp2=0;

        limit1=limit2=0;
        universalcount=0;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                mat[i][j]=0;
                puzzmat[i][j]=0;
            }

        }
        diffi=0;
    }

    void collectorarrayinitialiser()
    {
        for(int i=1;i<=9;i++)
        {
            //collectorarrayrow[i]=0;
            //collectorarraycol[i]=0;
            collectorarray[i]=0;
            eligiblenos[i]=0;
        }
        eligiblenos[0]=-1;
        eligiblenos[1]=-2;
        eligiblenos[2]=-3;
        eligiblenos[3]=-4;
        eligiblenos[4]=-5;
        eligiblenos[5]=-6;
        eligiblenos[6]=-7;
        eligiblenos[7]=-8;
        eligiblenos[8]=-9;
        eligiblenos[9]=-10;
        toteligiblenos=0;

    }

    /*
    void checkrowcol(int er,int row,int ec,int col)
    {
        collectorarrayinitialiser();
        for(int j=(er-3);j<er;j++)
        {
            collectorarray[mat[row][j]]=mat[row][j];
        }
        for(int i=(ec-3);i<ec;i++)
        {
            collectorarray[mat[i][col]]=mat[i][col];
        }
        for(int i=1,int j=1;i<9;i++)
        {

            if(collectorarrayrow[i]==0 && collectorarraycol[i]==0)
            {
                toteligiblenos++;
                eligiblenos[j]=i;
                j++;
            }

        }
        static std::default_random_engine e{};
        static std::uniform_int_distribution<int> d{1, toteligiblenos};
        r=eligiblenos[d(e)];
    }

    */

    int checkrowcol2(int er,int row,int ec,int col,int x,int y)
    {
        upabove:

        collectorarrayinitialiser();

        for(int i=x;i<x+3;i++)      // like checkblock
        {
            for(int j=y;j<y+3;j++)
            {
                collectorarray[mat[i][j]]=mat[i][j];
            }
        }

        for(int j=0;j<er;j++)
        {
            collectorarray[mat[row][j]]=mat[row][j];
        }
        for(int i=0;i<ec;i++)
        {
            collectorarray[mat[i][col]]=mat[i][col];
        }
        int i,j;
        for(i=1,j=1;i<=9;i++)
        {

            if(collectorarray[i]==0)
            {
                toteligiblenos++;
                eligiblenos[j]=i;
                j++;
            }

        }

        if(toteligiblenos==0)
        {
            makezero(x,y);
            return 0;
            //goto upabove;
        }

        /*
        cout<<"\n\n";
        for(int i=1;i<=9;i++)
            cout<<" collectora["<<i<<"] : "<<collectorarray[i];

        cout<<"\n\n";
        cout<<"\n eligiblenos[1]="<<eligiblenos[1]<<"  eligiblenos[2]="<<eligiblenos[2]<<"  eligiblenos[3]="<<eligiblenos[3]<<"  eligiblenos[4]="<<eligiblenos[4]<<"  eligiblenos[5]="<<eligiblenos[5];
        */
        int temp=0;
        littleup:
        //static std::default_random_engine e{};
        //static std::uniform_int_distribution<int> d{1, toteligiblenos};
        temp=(rand()%toteligiblenos)+1;

        //r=eligiblenos[d(e)];
        r=eligiblenos[temp];
        if(r<=0)
            goto littleup;
        //cout<<"\n Random Number chosen : "<<r<<"  From index : "<<"  Total elig : "<<toteligiblenos;
        return 1;
    }

    int checkblock(int r,int e1,int e2)        //for checking current block
    {
        int i,j;
        for(i=(e1-3);i<e1;i++)
        {
            //cout<<"\n i : "<<i<<"  &  j : ";
            for(j=(e2-3);j<e2;j++)
            {
                //cout<<j<<",";
                if(mat[i][j]==r)
                    return 0;
                else
                    continue;
            }

        }
        //cout<<"\n\n\n";
        return 1;
    }

    void initialdiagonal()
    {
        //srand(time(0));


          //Random number tester.

        /*

        char ch;
        do{
                /*
        int r=(rand()%9)+1;
        cout<<"\n Random int : "<<r<<endl;


        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist9(1,9);
        cout<<"\n "<<dist9(rng);

        cout<<"\n Continue? y/n?";
        cin>>ch;
        }while(ch=='y' || ch=='Y');

        */

        int i,j;
        //int r=0;
        int counter=0;
        limit1=0;
        limit2=0;

        while(counter!=3)
        {
            i=limit1;
            j=limit2;
            int temp1=limit1;
            int temp2=limit2;
            limit1=limit1+3;
            limit2=limit2+3;
            for(i=temp1;i<limit1;i++)
            {
                for(j=temp2;j<limit2;)
                {
                    //r=(rand()%9)+1;

                    //static std::default_random_engine e{};
                    //static std::uniform_int_distribution<int> d{1, 9};
                    r=(rand()%9)+1;
                    //r=d(e);

                    if(checkblock(r,limit1,limit2))
                    {
                        mat[i][j]=r;
                        j++;
                    }
                    else
                        continue;
                }
            }
            counter++;
        }

        //clock_t psta=clock();

        stagetwo(0,3);

    }

    int getnewrandom(int r)
    {
        int newr=0;

        while(1)
        {
            static std::default_random_engine e{};
            static std::uniform_int_distribution<int> d{1, 9};
            newr=d(e);
            if(newr!=r)
                return newr;
        }
    }

    void stagetwo(int i,int j)  //comparing with two other blocks besides the current block
    {
        //auto start = high_resolution_clock::now();

        clock_t begin = clock();

        //srand(time(0));

        if(flag==1 && counter2>=0)
        {
            //flag=0;
            goto switchlabel;
        }

        //int counter2=0;

        int res;

        while(counter2<6)
        {
            startofw:
        for(int l=i;l<(i+3);l++)
        {
            //inbetween:
            for(int m=j;m<(j+3);)
            {
                //startofm:
                res=appfuncaller(i,j,l,m);

                if(res==0)
                {

                {
                    clock_t end = clock();

                double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

                if(elapsed_secs>60)
                {
                    cout<<"\n\n RESET! \n ******* \n ******* \n &&&&&&& \n";
                    throw 'b';
                }

                else if(elapsed_secs>4)
                {
                    universalcount++;
                    //cout<<"\n\n Oh no! ";
                    //cout<<"\n Throwing an exception now! \n";

                    if(universalcount>8)
                    {
                        throw 'a';
                    }
                    else if(universalcount>2)
                    {
                        throw 3.5;
                    }
                    else
                        throw 0;

                }

                }

                    goto startofw;
                }


                if(checkblock(r,i+3,j+3))    //if(appfuncaller(i,j,l,m,r))
                {
                    string msg="instagetwo";
                    mat[l][m]=r;
                    //display(mat,msg);
                    m++;
                }
                else
                    continue;
            }
        }
        counter2++;
        //label2:
        tempp=0;
        switchlabel:
        //if(counter2<5)
        switch(counter2)
        {
        case 0 :
            i=0;
            j=3;
            if(flag==1)
            {
                flag=0;
                if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }
            else
            {
                //cout<<"\n Hello 0 ";
                //makezero(i,j);
            }

            }
            break;

        case 1 :
            i=3;
            j=0;
            if(flag==1)
            {
                flag=0;
                if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }
            else
            {
                //cout<<"\n Hello 1 ";
                //makezero(i,j);
            }
            }
            break;

        case 2 :
            i=3;
            j=6;
            if(flag==1)
            {
                flag=0;
                if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }
            else
            {
                //cout<<"\n Hello 2 ";
                //makezero(i,j);
            }
            }
            break;

        case 3 :
            i=6;
            j=3;
            if(flag==1)
            {
                flag=0;
                if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }
            else
            {
                //cout<<"\n Hello 3 ";
                //makezero(i,j);
            }
            }
            break;

        case 4 :
            i=6;
            j=0;
            if(flag==1)
            {
                flag=0;
                if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }

            else
            {
                //cout<<"\n Hello 4 ";
                //makezero(i,j);
            }
            }
            break;

        case 5 :
            i=0;
            j=6;
            if(flag==1)
            {
                flag=0;
                if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }

            else
            {
                //cout<<"\n Hello 5 ";
                //makezero(i,j);
            }
            }
            break;

        default :
            ;
        }


        //break;
        }

        //stagethree(6,0);
    }

    int appfuncaller(int i,int j,int l,int m)          // appropriate function caller
    {
        int res;

        if(i==0 && j==3)
        {
            //checkblock(r,i+3,j+3);
            res=checkrowcol2(i+3,l,j+3,m,i,j);
            if(res==1)
                return 1;
            else
                return 0;
        }

        if(i==3 && j==0)
        {
            //checkblock(r,i+3,j+3);
            res=checkrowcol2(i+3,l,j+3,m,i,j);
            if(res==1)
                return 1;
            else
                return 0;
        }

        if(i==3 && j==6)
        {
            //checkblock(r,i+3,j+3);
            res=checkrowcol2(i+3,l,j+3,m,i,j);
            if(res==1)
                return 1;
            else
                return 0;
        }

        if(i==6 && j==3)
        {
            //checkblock(r,i+3,j+3);
            res=checkrowcol2(i+3,l,j+3,m,i,j);
            if(res==1)
                return 1;
            else
                return 0;
        }

        if(i==6 && j==0)
        {
            res=checkrowcol2(i+3,l,j+6,m,i,j);
            if(res==1)
                return 1;
            else
                return 0;
        }

        if(i==0 && j==6)
        {
            res=checkrowcol2(i+6,l,j+3,m,i,j);
            if(res==1)
                return 1;
            else
                return 0;
        }

    }

    void inithashtable()
    {
        for(int k=1;k<10;k++)
        {
            hashtable[k]=0;
        }
    }

void display(int mat[10][10],string msg)
{
    cout<<"\n\t\t Finally : "<<msg<<" : ";
    for(int i=0;i<9;i++)
    {
        cout<<endl;
        if(i==0)
        {
            cout<<"  -------------------------------------"<<endl;
            cout<<"  |           |           |           | "<<endl;
        }

        //cout<<"\t"<<endl;
        /*if(i%3==0)
            cout<<"------------------";*/
        for(int j=0;j<9;j++)
        {
            if(j==0)
            {
                cout<<"  |  ";
                cout<<mat[i][j];
                continue;
            }

            cout<<"  "<<mat[i][j];
            if(j==2 || j==5 || j==8)
            {
                cout<<"  |";
            }
        }
        cout<<endl;
        cout<<"  |           |           |           | ";
        if(i==2 || i==5 || i==8)
        {
            cout<<endl<<"  -------------------------------------"<<endl;
            if(i!=8)
                cout<<"  |           |           |           | ";
        }

    }
    cout<<"\n Universal Counter : "<<universalcount;
    cout<<"";
}

    void makezero(int i,int j)             // passing starting points as parameters
    {
        int temp1=i;
        int temp2=j;
        for(i=temp1;i<temp1+3;i++)
        {
            for(j=temp2;j<temp2+3;j++)
            {
                mat[i][j]=0;
            }
        }
    }

    void getijfromcounter2()
    {
        int i,j;

        switch(counter2)
        {
        case 0 :
            i=0;
            j=3;
            if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }
            else
            {
                //cout<<"\n Hello 0 ";
                makezero(i,j);
            }

            break;

        case 1 :
            i=3;
            j=0;
            if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }
            else
            {
                //cout<<"\n Hello 1 ";
                makezero(i,j);
            }

            break;

        case 2 :
            i=3;
            j=6;
            if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }
            else
            {
                //cout<<"\n Hello 2 ";
                makezero(i,j);
            }
            break;

        case 3 :
            i=6;
            j=3;
            if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }
            else
            {
                //cout<<"\n Hello 3 ";
                makezero(i,j);
            }

            break;

        case 4 :
            i=6;
            j=0;
            if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }

            else
            {
                //cout<<"\n Hello 4 ";
                makezero(i,j);
            }

            break;

        case 5 :
            i=0;
            j=6;
            if(isfull(i,j))
            {
                //cout<<"\n Full ";
            }

            else
            {
                //cout<<"\n Hello 5 ";
                makezero(i,j);
            }

            break;

        default :
            ;
        }
    }

    /*

    void getijfromcounter2()
    {
        int i,j;

        int tempflag=0;
        int temp=counter2;
        if(temp>1)
        {
            temp--;
            tempflag=1;
        }


        label6:

        switch(temp)
        {
        case 0 :
            i=0;
            j=3;

            {
                cout<<"\n Hello 0000 ";
                makezero(i,j);
            }

            break;

        case 1 :
            i=3;
            j=0;

            {
                cout<<"\n Hello 1111 ";
                makezero(i,j);
            }

            break;

        case 2 :
            i=3;
            j=6;

            {
                cout<<"\n Hello 2222 ";
                makezero(i,j);
            }

            break;

        case 3 :
            i=6;
            j=3;

            {
                cout<<"\n Hello 3333 ";
                makezero(i,j);
            }

            break;

        case 4 :
            i=6;
            j=0;

            {
                cout<<"\n Hello 4444 ";
                makezero(i,j);
            }

            break;

        case 5 :
            i=0;
            j=6;

            {
                cout<<"\n Hello 5555 ";
                makezero(i,j);
            }

            break;

        default :
            ;
            cout<<"\n Default? WTF! It was you all along? ";
        }
        if(tempflag==1)
        {
            tempflag=0;
            temp++;
            counter2--;
            goto label6;
        }
    }

    */

    void createobj()
    {
        SudokuGen dobj;

    }

    int isfull(int i,int j)               // check if a block is complete or not
    {
        int tempflag=0;
        int temp1=i;
        int temp2=j;
        for(i=temp1;i<temp1+3;i++)
        {
            for(j=temp2;j<temp2+3;j++)
            {
                if(mat[i][j]!=0)
                {
                    tempflag=1;
                }
                else
                {
                    tempflag=0;
                    break;
                }

            }
        }
        if(tempflag==1)
        {
            tempflag=0;
            return 1;
        }
        else
            return 0;
    }

    void makedummy()
    {
        //int dummy[10][10];
        //int arr[82];                // for hardcoding a previous generated puzzle
        int counter4=0;

        int arr[82]={2,7,9,1,6,4,5,3,8,1,8,3,2,7,5,6,4,9,6,4,5,9,3,8,1,7,2,9,6,7,5,8,2,3,1,4,3,5,4,7,1,9,8,2,6,8,2,1,3,4,6,7,9,5,4,1,6,8,2,3,9,5,7,5,3,8,4,9,7,2,6,1,7,9,2,6,5,1,4,8,3,0};

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                dummy[i][j]=arr[counter4];
                counter4++;
            }
        }
    }

    void removesome()
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                //char temp=mat[i][j];
                //char temp=dummy[i][j];
                //cout<<"\n Char Temp : "<<temp<<endl;
                puzzmat[i][j]=mat[i][j];
                //puzzmat[i][j]=dummy[i][j];
            }
        }

        cout<<"\n Enter the difficulty ";
        cout<<"\n\t a. 30-Easy \n\t b. 45-Medium \n\t c. 54-Hard \n";
        cin>>diffi;

        actualremove();

        /*
        switch(diffi)
        {
        case 8 :
            actualremove();
            break;
        }
        */

    }

    void initialisepuzzmat()
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                puzzmat[i][j]=0;
            }
        }
    }

    void actualremove()
    {
        int counter3=diffi;

        int r1,r2;

        for(int k=0;k<counter3;)
        {
            r1=(rand()%9)+1;
            //delay(100);
            r2=(rand()%9)+1;

            if(puzzmat[r1][r2]!=0)
            {
                puzzmat[r1][r2]=0;
                k++;
            }

            /*
            if(puzzmat[r1][r2]!=' ')
            {
                puzzmat[r1][r2]=' ';
                k++;
            }
            */


        }

    }

    void matrixdispselector()      // so that I won't have to make the matrices public.
    {
        int ch;
        for (int i=0; i<9; i++)
		{
			cout<<endl;
			for (int j=0; j<9; j++)
			{
				cout<<mat[i][j];
			}
		}
        cout<<"\n Enter which matrix you want to be display : ";
        cout<<"\n\t 1. Mat \n\t 2. Puzzmat \n\t 3. Dummy \n";
        cin>>ch;
	
	//22 April, 2020 Update:
	
	ofstream fout;
	ifstream fin;
	string line;
	vector<string> alreadyEnteredBasePuzzles;
	fin.open("/home/s/Sudoku_generator/Generated_Puzzles/BasePuzzles.txt");
	while (fin)
	{
		getline(fin, line);
		alreadyEnteredBasePuzzles.push_back(line);
	}
	fin.close();
	line = "";
	fout.open("/home/s/Sudoku_generator/Generated_Puzzles/BasePuzzles.txt", ios::app);
	if (fout)
	{
		for (int i=0; i<9; i++)
		{
			for (int j=0; j<9; j++)
			{
				string temp = to_string(mat[i][j]);
				//fout<<mat[i][j];
				line.append(temp);
			}
		}
		//fout<<endl;
	}
	int flag = 0;
	for (int i=0; i<alreadyEnteredBasePuzzles.size();i++)
	{
		if (alreadyEnteredBasePuzzles[i].compare(line) == 0)
		{
			cout<<"Whoa! The puzzle already exists! What are the odds!";
			flag = 1;
			break;
		}
	}
	if (flag != 1)
	{
		fout<<line<<endl;
		flag = 0;
	}
	fout.close();
	//22 April, 2020 Update;
		
        string msg;

        switch(ch)
        {
        case 1 :
            msg="Mat";
            display(mat,msg);
            break;

        case 2 :
            msg="Puzzmat";
            display(puzzmat,msg);
            break;

        case 3 :
            msg="Dummy";
            display(dummy,msg);
            break;

        default :
            ;
        }
    }

};

int main()
{
    int times=-1;;
    //srand(GetTickCount());
    struct timespec ts;
    
    srand(clock_gettime(CLOCK_MONOTONIC, &ts));

    label1:

        times++;
        if(times!=0)
            cout<<"\n\n Times the program was reinitialized and rerun : "<<times<<endl;
        clock_t psta=clock();
        clock_t pend;

    SudokuGen *obj=new SudokuGen;

    //obj.createobj();

    //clock_t begin = clock();

    int para=0;

    int t=0;
    while(1)
    {
        try
        {
            if(para==2)
            {
                para=0;
                //obj->stagethree(6,0);
                break;
            }

            //cout<<"\n D1 \n";
            if(obj->flag==1)
            {//cout<<"\n D2 \n";
                obj->stagetwo(0,3);
                break;
            }
            else
            {
                obj->initialdiagonal();
                break;
            }

        }


    catch(char ex)
    {
        cout<<"\n Deleting the link to the object now! ";
        delete obj;
        goto label1;
    }


    catch(double b)
    {
        //cout<<"\n In the new catch block (float). ";
        obj->flag=1;



        pend=clock();
        double ptime_secs = double(pend - psta) / CLOCKS_PER_SEC;

        if(ptime_secs>15)
        {
            cout<<"\n Deleting the link to the object now! ";
            cout<<"\n\n RESET! In main() \n ******* \n ******* \n &&&&&&& \n";
            delete obj;
            goto label1;
        }



        cout<<"\n "<<obj->tempp;
        //if(obj->counter2>1)
            //obj->counter2--;
        obj->getijfromcounter2();
        //obj->counter2++;
        //if(obj->counter2>0)
            //obj->counter2--;
        //obj->stagetwo(0,3);
    }


    ////*
    catch(int a)
    {
        if(a==2)
        {
            para=2;
        }
        else
        {
            //cout<<"\n In the new catch block. ";
            obj->flag=1;
        }

        //obj->stagetwo(0,3);
    }
    //*/
    //t++;
    //cout<<"\n t = "<<t;
    //obj->stagetwo(0,3);
    }



    obj->matrixdispselector();


    //clock_t end = clock();
    //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    /*
    if(elapsed_secs>10)
    {
        cout<<"\n Deleting the link to the object now! ";
        delete obj;
        goto label1;
    }
    */

    /*          the display calls in this block got replaced with matrixdispselector() function;
    string msg;

    msg="Mat";
    obj->display(obj->mat,msg);
    obj->makedummy();
    obj->removesome();
    msg="Dummy";
    obj->display(obj->dummy,msg);
    msg="Puzzmat";
    obj->display(obj->puzzmat,msg);
    */

    //obj->makedummy();

    char choice;

    do
    {

    //cout<<"\n Enter the number corresponding to your choice : ";

    obj->initialisepuzzmat();
    obj->removesome();
    obj->matrixdispselector();
    //obj->matrixdispselector();

    cout<<"\n Do you want to create another puzzle out of this matrix? y/n?";
    cin>>choice;

    }while(choice=='y' || choice=='Y');

    return 0;
}
