#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
	char name[50];
	char dept[5];
	int sem;
	char rollno[10];
    int mcc_attended;
    int percent_attendance;
    int attended[5];
	int conducted[5];
	char exam_applied[5];
	int fee_status;
	
    struct Node* next;
};

struct Node_feeStatus {
  char rollno[10];
  int fee_status;
  struct Node_feeStatus* next;

};

struct Node_applicant {
  char name[50];
  char rollno[10];
  char exam_applied[5];
  struct Node_applicant* next;
};

struct Node_attendance {
  char rollno[10];
  char dept[5];
  int mcc_attended;
  int percent_attendance;
  struct Node_attendance* next;
};

void display(struct Node *head);
struct Node* sortSemester(struct Node* head);
struct Node* sortDepartment(struct Node* head);
struct Node* insertAtEnd(struct Node* tail,struct Node* p);
struct Node* sortRollNo(struct Node* head);
void updateMCC(struct Node* head);
struct Node* eligable_form(struct Node* head);
struct Node* NA_form(struct Node* head);
struct Node* defaulter_form(struct Node* head);
void dept_max_defaulter(struct Node* head);
struct Node* sort_q5(struct Node* head);
struct Node_feeStatus* makeNode_feeStatus( struct Node* head);
struct Node_feeStatus* formList_feeStatus( struct Node* head);
void display_feeStatus( struct Node_feeStatus* head);
struct Node_applicant* makeNode_applicant (struct Node* head);
struct Node_applicant* formList_applicant (struct Node* head);
void display_applicant(struct Node_applicant* head);
struct Node* less_75_form(struct Node* head);


int main() 
{
	FILE * f_ptr;
	int read, line=0, i=0;
	
	char name[50];
	char dept[5];
	int sem;
	char rollno[10];
	int attended[5];
	int conducted[5];
	char fee_status_str[10];
	char exam_applied[5];

	int fee_status;
	
	struct Node *temp;
	struct Node *studentList;
	studentList = (struct Node *) malloc(sizeof(struct Node)); // head of the list ,dummy node
	
	temp = studentList;
	
	f_ptr = fopen("data.txt", "r");
	
	// Priya Parab, CS, 2, BT21CS001, 40,40,40,40,50, 30,30,30,35,50,clear,A %4[^,]
	// %49[^,],%4[^,],%d,%9[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%9[^,],%4[^,]
	// %s,%s,%d,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%s,%s
	do{
		read = fscanf (f_ptr, "%d,%49[^,],%4[^,],%d,%9[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%9[^,],%s", &i, name, dept, &sem, rollno, 
		&conducted[0], &attended[0], &conducted[1], &attended[1], &conducted[2], &attended[2], &conducted[3], &attended[3], &conducted[4], &attended[4],	
		fee_status_str, exam_applied);
    
    	line++;
    	
    	if (read != 17 && !feof(f_ptr))
    	{
      		printf("\nline no = %d , File format incorrect.\n", line);    		
    	}
    
    	if (ferror(f_ptr))
    	{
      		printf("Error reading file.\n");
    	}
    	
    	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
  		strcpy(newNode->name, name);
  		strcpy(newNode->dept, dept);
  		newNode->sem = sem;
  		strcpy(newNode->rollno, rollno);
  		
  		newNode->conducted[0] = conducted[0];
  		newNode->conducted[1] = conducted[1];
  		newNode->conducted[2] = conducted[2];
  		newNode->conducted[3] = conducted[3];
  		newNode->conducted[4] = conducted[4];
  		
  		newNode->attended[0] = attended[0];
  		newNode->attended[1] = attended[1];
  		newNode->attended[2] = attended[2];
		newNode->attended[3] = attended[3];
  		newNode->attended[4] = attended[4];
  		
  		newNode->mcc_attended = 0;
  		newNode->percent_attendance = 0;
  		
  		if(strcmp(fee_status_str, "pending")==0)
  		{
  			newNode->fee_status = 1;
		} else {
			newNode->fee_status = 0;
		}
		
		strcpy(newNode->exam_applied, exam_applied);
		
  		newNode->next = NULL;
  		
    	temp->next = newNode;
    	temp = temp->next;    
		
	} while (!feof(f_ptr) && (read==17));


   	fclose(f_ptr); 
   	
   	// first node in the list is dummy, now remove it
   	temp = studentList;
   	studentList = temp->next; // correct head
   	free(temp);
   		

  struct Node* list_head= studentList;


  formList_applicant(list_head);

    //----------------Q1----------------------------------------------------------------//
	// struct Node* head = studentList;
	
	// head = sortRollNo(head);
	// head = sortDepartment(head); 
	// head = sortSemester(head);

	// updateMCC(head);	
  //   head=eligable_form(head);
	// display(head);

    //-----------------Q2----------------------------------------------------------------//
        
    // struct Node* head_2 = NA_form(studentList);

    // head_2 = sortDepartment(head_2);
    // head_2 = sortSemester(head_2);  
    // display(head_2);
    
    //-------------Q3----------------------------------------------------------------//

    // struct Node* head_3 = studentList;
    // updateMCC(head_3);
    // head_3 = eligable_form(head_3);
    // head_3 = sortDepartment(head_3);
    // head_3 = sortSemester(head_3);
    
    // display(head_3); 



    //------------Q4-------------------------------------------------------------------//

    // struct Node* head_4 = studentList;
    // updateMCC(head_4);
    // head_4 = less_75_form(head_4);
    // head_4 = sortRollNo(head_4);
	  // head_4 = sortDepartment(head_4); 
	  // head_4 = sortSemester(head_4);
    // display(head_4);


    //------------Q5-------------------------------------------------------------------//

    // struct Node* ptr_5= studentList;
    // updateMCC(ptr_5);
    // ptr_5 = sort_q5(ptr_5);
    // display(ptr_5);
    


    //------------Q6-------------------------------------------------------------------//

    // struct Node* head_6 = sortDepartment(studentList);
    // updateMCC(head_6);
    // head_6 = defaulter_form(head_6);
    // dept_max_defaulter(head_6);

}



struct Node* NA_form(struct Node* head)
{
    struct Node* head_2= NULL;  //head to list 
    struct Node* ptr_2= NULL;     //pointer to the list
    struct Node* temp_2 = head;         // traversing the general student main list

    while( temp_2!= NULL )
    {
        if( strcmp(temp_2->exam_applied,"NA") == 0 )
        {
            if(head_2 == NULL)
            {
               head_2 = temp_2;
                ptr_2= temp_2;
            }
            else
            {
                ptr_2->next = temp_2;
                ptr_2=ptr_2->next;
            }
        }
        temp_2=temp_2->next;
    }
    if( ptr_2 != NULL)
    {
      ptr_2->next=NULL;
    }
    return head_2;
}

struct Node* eligable_form(struct Node* head)
{
    struct Node* ptr_eligable = NULL;
    struct Node* head_ptr_eligable = NULL;
    struct Node* ptr= head;

    while( ptr!=NULL )
    {
        if( (ptr->percent_attendance > 75) && (ptr->fee_status==0) && (strcmp(ptr->exam_applied,"A")==0) )
        {
            if( head_ptr_eligable == NULL)
            {
                head_ptr_eligable = ptr;
                ptr_eligable = ptr;
            }
            else
            {
                ptr_eligable->next=ptr;
                ptr_eligable=ptr_eligable->next;
            }
        }
        
        ptr=ptr->next;
    
    }
    if( ptr_eligable!=NULL )
    {
      ptr_eligable->next=NULL;
    }
	  return head_ptr_eligable;
}

struct Node* defaulter_form(struct Node* head)
{
    struct Node* ptr_defaulter = NULL;
    struct Node* head_ptr_defaulter = NULL;
    struct Node* ptr= head;

    while( ptr!=NULL )
    {
        if( (ptr->percent_attendance <= 75) || (ptr->fee_status==1)  )
        {
            if( head_ptr_defaulter == NULL)
            {
                head_ptr_defaulter = ptr;
                ptr_defaulter = ptr;
            }
            else
            {
                ptr_defaulter->next=ptr;
                ptr_defaulter=ptr_defaulter->next;
            }
        }
        
        ptr=ptr->next;
    
    }
    if( ptr_defaulter != NULL)
    {
      ptr_defaulter->next=NULL;
    }
	  return head_ptr_defaulter;
}

void updateMCC(struct Node *head)
{
	struct Node * temp = head; 
	
	int i=0, j=0, sem_index, dept_index, max_conducted, mcc_sub;
	//int sem;
	
	// each entry gives the subject index of MCC for a dept and for a sem,
	// 5 dept (row wise), 4 semesters (column wise), MCC [0][0] - CS and 2 nd semester
	int MCC[5][4]; 	
	
	int max_attended [5][4]; // max_attended [0][0] - in CS for 2 nd semester, what is the max no of lectures attended for MCC
	
	//initialize
	for(i=0; i<5; i++){
		for(j=0;j<4;j++){
			MCC[i][j] = -1;
			max_attended[i][j] = -1; 
		}
    }
	while (temp != NULL)
    {	
    	sem_index =  ((temp->sem) /2) -1;
    	
    	if(strcmp(temp->dept, "CS") == 0)
    		dept_index =0;
    	else if(strcmp(temp->dept, "CV") == 0)
    		dept_index =1;
    	else if(strcmp(temp->dept, "EC") == 0)
    		dept_index =2;
		else if(strcmp(temp->dept, "EE") == 0)
    		dept_index =3;
		else if(strcmp(temp->dept, "ME") == 0)
    		dept_index =4;	
		
    	if(MCC[dept_index][sem_index]==-1)
    	{
    		max_conducted = temp->conducted[0]; // max conducted lectures
    		mcc_sub = 0; // subject index
    		
    		for(i=1; i<5; i++)
			{
				if(temp->conducted[i] > max_conducted)	
				{
					max_conducted = temp->conducted[i];
					mcc_sub = i;
				}
			}
			MCC[dept_index][sem_index] = mcc_sub; 
			max_attended[dept_index][sem_index] = temp->attended[mcc_sub];

		} 
		else
		{
			mcc_sub = MCC[dept_index][sem_index];
			if(temp->attended[mcc_sub] > max_attended[dept_index][sem_index])
			{
				max_attended[dept_index][sem_index] = temp->attended[mcc_sub];
			}
		}
	
  
  		temp = temp->next;
    	
	}

    temp = head;
 	while (temp != NULL)
    {	
    	sem_index =  ((temp->sem) /2) -1;
    	
    	if(strcmp(temp->dept, "CS") == 0)
    		dept_index =0;
    	else if(strcmp(temp->dept, "CV") == 0)
    		dept_index =1;
    	else if(strcmp(temp->dept, "EC") == 0)
    		dept_index =2;
		else if(strcmp(temp->dept, "EE") == 0)
    		dept_index =3;
		else if(strcmp(temp->dept, "ME") == 0)
    		dept_index =4;	
		
		mcc_sub = MCC[dept_index][sem_index]; // mcc_sub is the subject for which max classes are conducted
		
		temp->mcc_attended = temp->attended[mcc_sub]; // student attended these many lectures for MCC
		
		temp->percent_attendance = (100 * temp->mcc_attended ) / max_attended[dept_index][sem_index];
		
  		temp = temp->next;
    	
	}   
    
    
}

void display(struct Node *head)
{   
    int i=1;
    while (head != NULL)
    {
        printf("\n\n i = %d Name = %s, Dept = %s, Sem = %d, Roll No = %s, Fee status = %d, Exam applied = %s, Percent Attendance = %d", i++, head->name, head->dept, head->sem, 
 				head->rollno, head->fee_status, head->exam_applied, head->percent_attendance);
		
        head = head->next;
    }
    printf("\n");
}

struct Node* sortSemester(struct Node* head)
{
  struct Node* sem_arr[4];
  struct Node* sem_arrT[4];
  int i;
  for(i=0;i<4;i++)
  {
    sem_arr[i]=NULL;
    sem_arrT[i]=NULL;
  }

  struct Node* temp=head;
  while(temp!=NULL)
  {
    int index=  ((temp->sem) /2) -1;
	
    if(sem_arr[index]==NULL)
    { 
      sem_arr[index]=temp;
      sem_arrT[index]=temp;

    }
    else 
    {
      sem_arrT[index]=insertAtEnd(sem_arrT[index],temp);
    }

    temp=temp->next;

  }
  struct Node* head_arr = NULL;
  struct Node* ptr = NULL;

  for(i=0;i<4;i++)
  {
    if( head_arr == NULL)
    {
      head_arr = sem_arr[i];
      ptr=sem_arrT[i];
    }
    else
    {
      if( sem_arr[i]!=NULL )
      {
        ptr->next = sem_arr[i];
        ptr= sem_arrT[i];
      }
    }
  }
  if ( ptr!=NULL)
  {
    ptr->next=NULL; 
  }
  return head_arr;
}

struct Node* insertAtEnd(struct Node* tail,struct Node* p)
{
  tail->next=p;
  tail=p;
  return tail;
}

struct Node* sortDepartment(struct Node* head){
  int i;
  // Creating an array of linked lists, with size 26, one for each alphabat
  struct Node* llArr[26];

  // We also need to keep track of tails, so that insertion operations happens in O(1)
  // So creating an array of tails
  struct Node* tails[26];

////////////////////////////////////////////////////////
  int offset = 1; // Offset is which character we are sorting by, first we check char at place 2, then 1, then at 0
  while(offset >= 0){
    // Initialising all the heads and tails
    for(i=0; i<26; i++){
      llArr[i] = NULL;
      tails[i] = NULL;
    }

    struct Node* temp = head; // To loop though the LL
    struct Node* prev = NULL; // To remove the unwanted links

    while(temp != NULL){
      
      // Getting index: 'a' means 0 index, 'b' means 1 index and so on
      int index = temp->dept[offset] - 'A';

      // Adding nodes to array and updating the tails
      if(llArr[index] == NULL){
        llArr[index] = temp;
        tails[index] = temp;
      }else{
        tails[index] = insertAtEnd(tails[index], temp);
      }

      // Removing unwanted links
      prev = temp;
      temp = temp->next;
      prev->next = NULL;
    }

    // Merging the new heads and tails
    int i=0;
    struct Node* prevTail = NULL;

    while(llArr[i] == NULL){
      i++;
    }

    head = llArr[i];
    prevTail = tails[i];
    i++;

    while(i < 26){
      if(llArr[i] != NULL){
        prevTail->next = llArr[i];
        prevTail  = tails[i];
      }

      i++;
    }
    // Merging finished

    offset--;
  }

  return head;
}

struct Node* sortRollNo(struct Node* head){
  int i;
  // Creating an array of linked lists, with size 26, one for each alphabat
  struct Node* llArr[10];

  // We also need to keep track of tails, so that insertion operations happens in O(1)
  // So creating an array of tails
  struct Node* tails[10];

////////////////////////////////////////////////////////
  int offset = 8; // BT21CS001 Offset is which character we are sorting by, first we check char at place 2, then 1, then at 0
  while(offset >= 6){
    // Initialising all the heads and tails
    for(i=0; i<10; i++){
      llArr[i] = NULL;
      tails[i] = NULL;
    }

    struct Node* temp = head; // To loop though the LL
    struct Node* prev = NULL; // To remove the unwanted links

    while(temp != NULL){
      
      // Getting index: 'a' means 0 index, 'b' means 1 index and so on
      int index = temp->rollno[offset] - '0';
      
      // Adding nodes to array and updating the tails
      if(llArr[index] == NULL){
        llArr[index] = temp;
        tails[index] = temp;
      }else{
        tails[index] = insertAtEnd(tails[index], temp);
      }

      // Removing unwanted links
      prev = temp;
      temp = temp->next;
      prev->next = NULL;
    }

    // Merging the new heads and tails
    int i=0;
    struct Node* prevTail = NULL;

    while(llArr[i] == NULL){
      i++;
    }

    head = llArr[i];
    prevTail = tails[i];
    i++;

    while(i < 10){
      if(llArr[i] != NULL){
        prevTail->next = llArr[i];
        prevTail  = tails[i];
      }

      i++;
    }
    // Merging finished

    offset--;
  }

  return head;
}

struct Node* less_75_form(struct Node* head)
{
    struct Node* ptr_less = NULL;
    struct Node* head_ptr_less = NULL;
    struct Node* ptr= head;

    while( ptr!=NULL )
    {
        if( (ptr->percent_attendance <= 75) )
        {
            if( head_ptr_less == NULL)
            {
                head_ptr_less = ptr;
                ptr_less = ptr;
            }
            else
            {
                ptr_less->next=ptr;
                ptr_less=ptr_less->next;
            }
        }
        
        ptr=ptr->next;
    
    }
    if( ptr_less!=NULL )
    {
      ptr_less->next=NULL;
    }
	  return head_ptr_less;
}

void dept_max_defaulter(struct Node* head)
{
  struct Node* ptr = head;
  char max_dept[5];
  strcpy( max_dept , head->dept );
  char curr_dept[5];
  strcpy(curr_dept, max_dept); 
  
  int max_count=1;
  int curr_count=1;

  while( ptr!= NULL && ptr->next != NULL)
  {
    if(strcmp(ptr->next->dept,ptr->dept)==0 )
    {
      curr_count++;
    }
    else
    {
      curr_count = 1;  
      strcpy(curr_dept,ptr->next->dept);
    }

    if( curr_count > max_count )
    {
      max_count = curr_count;
      strcpy(max_dept,curr_dept);
    }
    ptr=ptr->next;

  }
  printf("\n\nDepartment with maximum defaulters is %s . count=%d",max_dept, max_count);

}

struct Node* sort_q5(struct Node* head)
{
    struct Node* ptr_5 = NULL;
    struct Node* head_ptr_5 = NULL;
    struct Node* ptr= head;

    while( ptr!=NULL )
    {
        if( (ptr->fee_status==1) && ( ptr->percent_attendance > 75) )
        {
            if( head_ptr_5 == NULL)
            {
                head_ptr_5 = ptr;
                ptr_5 = ptr;
            }
            else
            {
                ptr_5->next=ptr;
                ptr_5=ptr_5->next;
            }
        }
        
        ptr=ptr->next;
    
    }
    if( ptr_5!=NULL )
    {
      ptr_5->next=NULL;
    }
	  return head_ptr_5;
}

struct Node_feeStatus* makeNode_feeStatus( struct Node* head)
{
  struct Node_feeStatus* newNode = malloc(sizeof(struct Node_feeStatus));
  strcpy(newNode->rollno, head->rollno);
  newNode->fee_status = head->fee_status;
  return newNode;  
}

struct Node_feeStatus* formList_feeStatus( struct Node* head)
{
  struct Node* ptr = head;

  struct Node_feeStatus* feeStatus_head = NULL;
  struct Node_feeStatus* feeStatus_ptr;

  while(ptr!= NULL)
  {
    if( feeStatus_head == NULL)
    {
      feeStatus_head = makeNode_feeStatus(ptr);
      feeStatus_ptr = feeStatus_head;
    }
    else
    {
      feeStatus_ptr->next = makeNode_feeStatus(ptr);
    }
    ptr = ptr->next;

  }
  return feeStatus_head;

}

void display_feeStatus( struct Node_feeStatus* head)
{
    int i=1;
    while (head != NULL)
    {
        printf("\n\n i = %d , Roll No = %s, Fee status = %d", i++, head->rollno, head->fee_status);
		
        head = head->next;
    }
    printf("\n");
}

struct Node_applicant* makeNode_applicant (struct Node* head)
{
  struct Node_applicant* newNode = malloc(sizeof(struct Node_applicant));
  strcpy(newNode->name, head->name);
  strcpy(newNode->rollno, head->rollno);
  strcpy( newNode->exam_applied,head->exam_applied);
  return newNode; 

}

struct Node_applicant* formList_applicant (struct Node* head)
{
  struct Node* ptr = head;

  struct Node_applicant* applicant_head = NULL;
  struct Node_applicant* applicant_ptr;

  while(ptr!= NULL)
  {
    if( applicant_head == NULL)
    {
      applicant_head = makeNode_applicant(ptr);
      applicant_ptr = applicant_head;
    }
    else
    {
      applicant_ptr->next = makeNode_applicant(ptr);
    }
    ptr = ptr->next;

  }
  return applicant_head;
}

void display_applicant(struct Node_applicant* head)
{
    int i=1;
    while (head != NULL)
    {
        printf("\n\n i = %d Name = %s, Roll No = %s,Exam applied = %s", i++, head->name, head->rollno,  head->exam_applied);
		
        head = head->next;
    }
    printf("\n");
}

