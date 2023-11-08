#include<stdio.h>
// #include<conio.h>
#include<string.h>
#include<ctype.h>
#include<process.h>
#include<stdlib.h>

typedef struct mnt  //Macro Name Table
{
 char mname[10];
 int mdt_index;
}mnt;

char mdt[100][40];     //Macro Defintion Table
mnt mn[10];

void main()
{
int mdt_pntr=0,mnt_pntr=0,v_pntr=0,i,j,loc_cnt=0,flag=0;
char temp[100],tkn[10][10],v[15][15],temp1[100],tkn1[10][10];
FILE *fp,*fp1;
// clrscr();
fp=fopen("abc.txt","r");
fp1=fopen("def.txt","w+");

if (fp==NULL)
 {
   printf("Cannot open output file.\n");
   exit(0);
 }

while(fgets(temp,40,fp))
{

 for(i=0;i<4;i++)
  strcpy(tkn[i],"");
 sscanf(temp,"%s %s %s %s",tkn[0],tkn[1],tkn[2],tkn[3]);

 if(strcmpi(tkn[0],"macro")!=0)
    printf("%s %s %s %s\t\t\n",tkn[0],tkn[1],tkn[2],tkn[3]); 
    // as it is print bcoz assebler statement

 else
  {
  for(i=0;i<4;i++)
  strcpy(tkn[i],"");
  fgets(temp,40,fp);
  sscanf(temp,"%s %s %s %s",tkn[0],tkn[1],tkn[2],tkn[3]);
  strcpy(mdt[mdt_pntr++],temp);
  strcpy(mn[mnt_pntr].mname,tkn[0]);
  mn[mnt_pntr].mdt_index=mdt_pntr-1;
  mnt_pntr++;
  //**************************************************

  for(i=1;i<4;i++)             // storing parameters in v[] array
  {
   if(tkn[i][0]=='&')
    {
     strcpy(v[v_pntr],tkn[i]);
     v_pntr++;
    }
  }

  //*************************
  while(fgets(temp,40,fp))
  {
  for(i=0;i<4;i++)
  strcpy(tkn[i],"");
  sscanf(temp,"%s %s %s %s",tkn[0],tkn[1],tkn[2],tkn[3]);

  if(strcmp(tkn[0],"mend")==0)    //if mend,store in MDT
  {
   strcpy(mdt[mdt_pntr++],temp);
   loc_cnt++;
   break;
  }


  for(i=0;i<v_pntr;i++)
  {
   if(strcmp(tkn[2],v[i])==0)
   { sprintf(temp,"%s %s %d %s \n",tkn[0],tkn[1],i,tkn[3]);
      strcpy(mdt[mdt_pntr++],temp);
	sprintf(temp,"%s %s %d %s\n",tkn[0],tkn[1],i,tkn[3]);

    break;
   }
  }

  }
v_pntr=0;
}
}

	printf("\n\n\t\t\tMNT  TABLE\n\n");
	printf("\tmnt index\tmnt name\tmdt index\n");
	printf("______________________________________________________\n\n");
	for(i=0;i<mnt_pntr;i++)
		printf("\t%d\t\t%s\t\t\t%d\n",i,mn[i].mname,mn[i].mdt_index
);
	// getch();
	 printf("\n\n\n");
	 printf("\t\t\tMDT  TABLE\n\n");
	printf("\tmdtindex \t macro def\n");
	printf("___________________________________________\n\n");
	for(i=0;i<mdt_pntr;i++)
	{
	  fprintf(fp1,"\t%d\t\t%s",i,mdt[i]);
	  printf("\t%d\t\t%s",i,mdt[i]);
	}
	// getch();
	fclose;

 //*--------- PASS-2 -----------
	// clrscr();
	printf("\n\t\t----Expansion of macro---- \n\n");
	fp=fopen("abc.txt","r");
	fp1=fopen("def.txt","r");
	printf(fgets(temp,40,fp));
	while(fgets(temp,40,fp))        //Skipping all macros
	{
	 if(strcmp("mend\n",temp)==0)
	  {
	   loc_cnt--;
	  }
	 if(loc_cnt==0)
	  break;
	}
	while(fgets(temp,40,fp))
	{ flag=0; rewind(fp1);
	  for(i=0;i<4;i++)
	  strcpy(tkn[i],"");
	  sscanf(temp,"%s %s %s %s",tkn[0],tkn[1],tkn[2],tkn[3]);
	  for(i=0;i<mnt_pntr;i++)       //Checking with all macro names
	  {
	  if(strcmp(mn[i].mname,tkn[0])==0)   //if macro
	   {flag=1;
	     while(fgets(temp1,40,fp1))       //use it's def.
	     {

		 sscanf(temp1,"%s %s %s %s",tkn1[0],tkn1[1],tkn1[2],tkn1[3],tkn1[4]);
if(atoi(tkn1[0])==mn[i].mdt_index)  //pointing to def.
		   {
		   while(fgets(temp1,40,fp1))
		   {
		   sscanf(temp1,"%s %s %s %s",tkn1[0],tkn1[1],tkn1[2], 
tkn1[3],tkn1[4]);
		    if (strcmp(tkn1[1],"mend")==0)
		      break;
		   if(strcmp(tkn1[3],"0")==0)
		     {
		     sprintf(temp1,"%s %s %s %s",tkn1[1],tkn1[2] 
  ,tkn[1]);
		     }
		     if(strcmp(tkn1[3],"1")==0)
		     {
		     sprintf(temp1,"%s %s %s %s",tkn1[1],tkn1[2] 
,tkn[2]);
		     }
		     if(strcmp(tkn1[3],"2")==0)
		     {
		     sprintf(temp1,"%s %s %s %s",tkn1[1],tkn1[2]
,tkn[3]);
		     }
		   printf("%s\n",temp1);

		   }
		   flag=1;
		   }

	     }
	     break;
	   }

	  }
		if(flag==0)
		  printf("%s",temp);
	  }

	// getch();
}



