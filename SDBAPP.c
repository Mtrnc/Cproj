#include <stdio.h>
#include "STD.h"
//Students database program.
typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;

}student;
student st[3];
uint32 id;
uint8 count=0 , size = 3;



void SDB_APP();//Function that runs the application
void SDB_action(uint8 c);//Function where to run the action from which the choice is chosen
bool SDB_IsFull();//Function to display whether the system is full or not
uint8 SDB_GetUsedSize();//Function to display the used the size out of the available size
bool SDB_AddEntry();//Function to add an entry
bool SDB_ReadEntry(uint32 id);//Function to display students data
void SDB_DeletEntry(uint32 id);//Function to add entry
void SDB_GetList(uint8* co , uint32* list);//Function to get the student count and the list of Array
bool SDB_IsIdExist (uint32 id);//Function to check if the ID exists or not

//Function to check if the database is full or not by if condition if the limit is reached then it will print out true else it will print out false
bool SDB_IsFull()
{

    if(count==3)
        {
            printf("Database is full %d\n" , true);
        }
   else
        {
            printf("Database is not full %d\n" , false);
        }

}

//Function to get the used size out of the available one by reading the values from count and size then printing them out
uint8 SDB_GetUsedSize()
{

   printf("Number of students added to the database: %d of %d\n" , count , size);

}
//In the add entry function it checks the student count if its on the limit then it will return 0.
// if not it will move to the else where a full loop will carry on the process of filling the database then as being done it will increment the count by 1.
bool SDB_AddEntry()
{

     int32 i;
     if(count==3)
     {
         printf("System is full");
     }
     else
     {
             for(i=count;i<=count;i++)
                {
                    printf("Please enter student %d ID: ", i+1);
                    scanf("%d" , &st[i].Student_ID);
                    printf("Please enter student %d year: ",i+1);
                    scanf("%d" , &st[i].Student_year);
                    printf("Please enter student %d course 1 ID: ",i+1);
                    scanf("%d" , &st[i].Course1_ID);
                    printf("Please enter  student %d course 1 grade: ",i+1);
                    scanf("%d" , &st[i].Course1_grade);
                    printf("Please enter student %d course 2 ID: ",i+1);
                    scanf("%d" , &st[i].Course2_ID);
                    printf("Please enter student %d course 2 grade: ",i+1);
                    scanf("%d" , &st[i].Course2_grade);
                    printf("Please enter student %d course 3 ID: ",i+1);
                    scanf("%d" , &st[i].Course3_ID);
                    printf("Please enter student %d course 3 grade: ",i+1);
                    scanf("%d" , &st[i].Course3_grade);
                }
             count++;
             return 1;
       {



       }
       count++;
      return 1;
}








 }
 //In the delete entry the ID value will be passed upon which its index number and position will be checked in if loop if it exists then it will move to the for loop that will compare its value with values in every index
 //if it does not match the value within a certain index it will continue until both values match once they match the struct contents will be deleted and the following element will replace it once the process is finished
 //it will move to the break statement then the count is decremented.
 void SDB_DeletEntry (uint32 id)
{
    int32 i , pos;
    for(i=0;i<=1;i++)
     {
         if(id==st[i].Student_ID)
         {
             pos = i;
             for (i = pos; i < size - 1; i++)
                {
                    st[i].Student_ID = st[i+1].Student_ID;
                    st[i].Student_year = st[i+1].Student_year;
                    st[i].Course1_ID = st[i+1].Course1_ID;
                    st[i].Course1_grade = st[i+1].Course1_grade;
                    st[i].Course2_ID = st[i+1].Course2_ID;
                    st[i].Course2_grade = st[i+1].Course2_grade;
                    st[i].Course1_ID = st[i+1].Course3_ID;
                    st[i].Course1_grade = st[i+1].Course3_grade;
                }

         }

         else if(id!=st[i].Student_ID)
         {
            continue;
         }

         else
         {
            break;
         }
         --count;




     }




}


//Function to read entry by passing the id number to it then it gets passed to a for loop that checks its content within the if statement comparing it to the struct ID content
//if they are equal the whole student struct contents are print32ed out , if not equal the it goes to the continue statement where steps are repeated again until its equal
//if it does not exist then it will return 0
bool SDB_ReadEntry (uint32 id)
{
     uint32 i;
     for(i=0;i<=size;i++)
     {
         if(id==st[i].Student_ID)
            {
                printf("Student ID: %d \n" , st[i].Student_ID );
                printf("Student year: %d \n" , st[i].Student_year);
                printf("Course1_ID: %d \n" , st[i].Course1_ID );
                printf("Course1_grade: %d \n" , st[i].Course1_grade);
                printf("Course2_ID: %d \n" , st[i].Course2_ID );
                printf("Course2_grade: %d \n" , st[i].Course2_grade);
                printf("Course3_ID: %d \n" , st[i].Course3_ID );
                printf("Course3_grade: %d \n" , st[i].Course3_grade);
                printf("Data exists %d\n" , true);
                break;
            }
         else
                continue;
     }


}



//Function to get the list and the count throughout pointers in included in the case function then displaying the students count and the list
void SDB_GetList (uint8* co , uint32* list)
{
     int32 i;
     for(i=0;i<=count-1;i++)
     {
        printf("Student %d ID: %d \n" , i+1 , st[i].Student_ID);

     }

}
bool SDB_IsIdExist (uint32 id)
{

     int32 i;
     for(i=0;i<=size;i++)
     {
         if(id==st[i].Student_ID)
            {
                printf("Student's ID exists %d \n" , true );
            }

         else if(id!=st[i].Student_ID)
            {
                continue;
            }

     }

}

void SDB_action(uint8 c)//Function of the cases each case will access a certain choice upon selection
{

     int32 x , i;
     uint32 list[3];
     uint8*p = &count;




     for(i=0 ; i<=count ; i++)
           {
               list[i] = st[i].Student_ID;
           }


   switch(c)
    {
     case '1':
        SDB_AddEntry();
        break;
     case '2':
        SDB_GetUsedSize();
        break;
     case '3':
        printf("Enter student's ID\n");
        scanf("%d" , &id);
        SDB_ReadEntry (id);
        break;
     case '4':
        SDB_GetList (&count  , &list);
        break;
     case '5':
        printf("Enter student's ID to be checked\n");
        scanf("%d" , &id);
        SDB_IsIdExist (id);
        break;
     case '6':
        printf("Enter student's ID to delete data\n");
        scanf("%d" , &id);
        SDB_DeletEntry (id);
        break;
     case '7':
        SDB_IsFull();
        break;
     case '8':
        exit(false);
        break;
    }

}
//The application function that will call the action function in a super loop to insert the choice number
void SDB_APP()
{
    printf("1. To add entry, enter 1\n");
    printf("2. To get used size in database, enter 2\n");
    printf("3. To read student data, enter 3 \n");
    printf("4. To get the list of all student IDs, enter 4\n");
    printf("5. To check is ID is existed, enter 5 \n");
    printf("6. To delete student data, enter 6\n");
    printf("7. To check is database is full, enter 7\n");
    printf("8. To exit enter 0\n");
    while(1)
    {
    uint8 c;


    scanf("%c" , &c);

    SDB_action(c);
    }

}
int main()//The main function to run the whole application
{
    SDB_APP();
    return 0;
}

