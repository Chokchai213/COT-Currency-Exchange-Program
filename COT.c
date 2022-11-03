#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#include<ctype.h>
struct currency
{
    float sell,buy,moneysell,moneybuy,rate,change,get,getint;
    struct currentname
    {
        char name[100];
    } cn;
} A[100],B[100],C[100],Buy[100],Sell[100],Buyprint[100],Sellprint[100]; // c ÊÓËÃÑº fscanf printf
FILE *fp;
FILE *hb;
FILE *hs;
int i;
void printbuy()
{

    hb = fopen("HistoryBuy.txt","r");
    int resb;
    fseek(hb,0,SEEK_END);
    resb = ftell(hb);
    fclose(hb);
    printf("\t\t\t--------------->>>Buy  History<<<---------------\n");
    printf("\nCurrency | Money (inserted) | Exchange rate | Expected Exchange | Real Exchange | Change");
    if(resb==0)
    {
        printf("\n\t\t\tNo buy history !!!\n");
    }
    else
    {
        hb = fopen("HistoryBuy.txt","r");
        while(!feof(hb))
        {
            fscanf(hb,"\n%s %f %f %f %f %f",C[i].cn.name,&C[i].moneybuy,&C[i].rate,&C[i].get,&C[i].getint,&C[i].change);
            printf("\n%s         %.2f Baht          %.2f         %.2f %s          %.0f %s    %.0f Baht\n",C[i].cn.name,C[i].moneybuy,C[i].rate,C[i].get,C[i].cn.name,C[i].getint,C[i].cn.name,C[i].change);
            i++;
        }
        fclose(hb);
    }

}
void printsell()
{
    hs = fopen("HistorySell.txt","r");
    int ress;
    fseek(hs,0,SEEK_END);
    ress = ftell(hs);
    fclose(hs);
    printf("\n\t\t\t--------------->>>Sell History<<<---------------\n");
    printf("\nCurrency | Money (inserted) | Exchange rate | Expected Exchange | Real Exchange |");
    if(ress==0)
    {
        printf("\n\t\t\tNo sell history !!!\n");
    }
    else
    {
        hs = fopen("HistorySell.txt","r");
        while(!feof(hs))
        {
            fscanf(hs,"\n%s %f %f %f %f",C[i].cn.name,&C[i].moneysell,&C[i].rate,&C[i].get,&C[i].getint);
            printf("\n%s           %.2f %s           %.2f          %.2f Baht          %.0f Baht\n",C[i].cn.name,C[i].moneysell,C[i].cn.name,C[i].rate,C[i].get,C[i].getint);
            i++;
        }
        fclose(hs);
    }

}

int BS(void) //v=1 buy v=0 sell
{
    char confirm[5];
    int cf, n,v;
    printf("Do you want to Exchange Money? : Buy / Sell \n");
    printf("Enter B=Buy or S=Sell\n");
    do
    {
        fflush(stdin);
        printf("Please Enter : ");
        gets(confirm);
    }
    while(strcmp(confirm,"S") != 0 && strcmp(confirm,"B") !=0&& strcmp(confirm,"b") !=0&& strcmp(confirm,"s") !=0);
    if(strcmp(confirm,"B")==0||strcmp(confirm,"b")==0)
    {
        v=1;
    }
    else
    {
        v=0;
    }
    return v;
}
char current[5][20] = {"USD","YUAN","YEN","POND","EURO"};

void menu()
{
    printf("\n\t\t\t================================================\n");
    printf("                      \t\t\t     MENU\n");
    printf("\t\t\t================================================\n");
    printf("\t\t\t1. Do transaction\n");
    printf("\t\t\t2. Change buy rate\n");
    printf("\t\t\t3. Change sell rate\n");
    printf("\t\t\t4. Rewrite buy&sell rate\n");
    printf("\t\t\t5. Check history\n");
    printf("\t\t\t6. Clear history\n");
    printf("\t\t\t0. Quit\n");
    printf("\t\t\t================================================\n");
}
int firstopen()
{
    int t=0,x=0,tn=0,id=1,c1=0,c2=0,c3=0,c4=0,c5=0,pat=0,n1=0,n2=0,n3=0,n4=0,n5=0;
    float buy,sell;
    char name[20];
    if((fp=fopen("Exchangerate.txt","r"))==NULL)
    {
        fclose(fp);
        printf("\t\tNO FILE EXIST \n");
        fp = fopen("Exchangerate.txt","w");
        printf("No File Exist so you have to add currency and their respective rates \n");
        printf("Please Insert Number according to choices below\n");
        do
        {
ple:
            x=9999;
            printf("1 = USD\n");
            printf("2 = YUAN\n");
            printf("3 = YEN\n");
            printf("4 = POND\n");
            printf("5 = EURO\n");
            printf("0 = QUIT\n");
            do
            {
                printf("Your Choice : ");
                scanf("%d",&x);
                fflush(stdin);
            }
            while(x!=1&&x!=2&&x!=3&&x!=4&&x!=5&&x!=0);
            switch(x)
            {
            case 1:
            {

                if(c1==1)
                {
                    printf("Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==1)
                {
                    printf("%s\n",current[x-1]);
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("Buy rate: ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("Sell rate: ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c1=1;
                    break;
                }
            }
            case 2:
            {
                if(c2==1)
                {
                    printf("Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==2)
                {
                    printf("%s\n",current[x-1]);
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("Buy rate: ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("Sell rate: ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c2=1;
                    break;
                }
            }
            case 3:
            {
                if(c3==1)
                {
                    printf("Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==3)
                {
                    printf("%s\n",current[x-1]);
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("Buy rate: ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("Sell rate: ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c3=1;
                    break;
                }
            }
            case 4:
            {
                if(c4==1)
                {
                    printf("Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==4)
                {
                    printf("%s\n",current[x-1]);
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("Buy rate: ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("Sell rate: ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c4=1;
                    break;
                }
            }
            case 5:
            {
                if(c5==1)
                {
                    printf("Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==5)
                {
                    printf("%s\n",current[x-1]);
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("Buy rate: ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("Sell rate: ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c5=1;
                    break;
                }

            }
            case 0:
            {
                id=0;
                goto BREAK;
            }
            default :
            {
                printf("Please be rational and input according to the information above \n");
                break;
            }
            }
        }
        while(id!=0);
    }
    id=1;
BREAK:
    fclose(fp);
}
int secondopen()
{
    int t=0,x=0,tn=0,id=1,c1=0,c2=0,c3=0,c4=0,c5=0,pat=0,n1=0,n2=0,n3=0,n4=0,n5=0;
    float buy,sell;
    char name[20];
        fp = fopen("Exchangerate.txt","w");
        printf("Please Insert Number according to choices below\n");
        do
        {
ple:
            x=9999,buy=0,sell=0;
            printf("1 = USD\n");
            printf("2 = YUAN\n");
            printf("3 = YEN\n");
            printf("4 = POND\n");
            printf("5 = EURO\n");
            printf("0 = QUIT\n");
            do
            {
                printf("Your Choice : ");
                scanf("%d",&x);
                fflush(stdin);
            }
            while(x!=1&&x!=2&&x!=3&&x!=4&&x!=5&&x!=0);
            switch(x)
            {
            case 1:
            {

                if(c1==1)
                {
                    printf("Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==1)
                {
                    printf("%s\n",current[x-1]);
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("Buy rate: ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("Sell rate: ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c1=1;
                    break;
                }
            }
            case 2:
            {
                if(c2==1)
                {
                    printf("Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==2)
                {
                    printf("%s\n",current[x-1]);
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("Buy rate: ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("Sell rate: ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c2=1;
                    break;
                }
            }
            case 3:
            {
                if(c3==1)
                {
                    printf("Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==3)
                {
                    printf("%s\n",current[x-1]);
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("Buy rate: ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("Sell rate: ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c3=1;
                    break;
                }
            }
            case 4:
            {
                if(c4==1)
                {
                    printf("Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==4)
                {
                    printf("%s\n",current[x-1]);
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("Buy rate: ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("Sell rate: ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c4=1;
                    break;
                }
            }
            case 5:
            {
                if(c5==1)
                {
                    printf("Already Enter Value %s \n",current[x-1]);
                    goto ple;
                }
                if(x==5)
                {
                    printf("%s\n",current[x-1]);
                    strcpy(name,current[x-1]);
                    fprintf(fp,"\n%s ",name);
                    do
                    {
                        buy=0;
                        printf("Buy rate: ");
                        scanf("%f",&buy);
                        fflush(stdin);
                        buy=buy+1;
                        buy=buy-1;
                    }
                    while(buy<=0);
                    fprintf(fp,"%.2f ",buy);
                    do
                    {
                        sell=0;
                        printf("Sell rate: ");
                        scanf("%f",&sell);
                        fflush(stdin);
                        sell=sell+1;
                        sell=sell-1;
                    }
                    while(sell<=0);
                    fprintf(fp,"%.2f",sell);
                    c5=1;
                    break;
                }

            }
            case 0:
            {
                id=0;
                goto BREAK;
            }
            default :
            {
                printf("Please be rational and input according to the information above \n");
                break;
            }
        }
        }
        while(id!=0);
    id=1;
BREAK:
    fclose(fp);
}
int table()
{
    int t;
    t=0;
    fp = fopen("Exchangerate.txt","r");
    printf("\t\t\t------------------------------\n");
    printf("\t\t\tCurrency   Buy     Sell\n");
    while(!feof(fp))
    {
        fscanf(fp,"%s %f %f",A[t].cn.name,&A[t].buy,&A[t].sell);
        printf("\t\t\t%-10s %8.2f   %8.2f\n",A[t].cn.name,A[t].buy,A[t].sell);
        t++;
    }
    printf("\t\t\t------------------------------\n");
    fclose(fp);
    return t;

}
void welcomemenu()
{

    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t  ______          _                              __  __            _     _               _____    ____    _______ \n");
    printf("\t\t\t\t |  ____|        | |                            |  \\/  |          | |   (_)             / ____|  / __ \\  |__   __|\n");
    printf("\t\t\t\t | |__  __  _____| |__   __ _ _ __   __ _  ___  | \\  / | __ _  ___| |__  _ _ __   ___  | |      | |  | |    | |   \n");
    printf("\t\t\t\t |  __| \\ \\/ / __| '_ \\ / _` | '_ \\ / _` |/ _ \\ | |\\/| |/ _` |/ __| '_ \\| | '_ \\ / _ \\ | |      | |  | |    | |   \n");
    printf("\t\t\t\t | |____ >  < (__| | | | (_| | | | | (_| |  __/ | |  | | (_| | (__| | | | | | | |  __/ | |____  | |__| |    | |   \n");
    printf("\t\t\t\t |______/_/\\_\\___|_| |_|\\__,_|_| |_|\\__, |\\___| |_|  |_|\\__,_|\\___|_| |_|_|_| |_|\\___|  \\_____|  \\____/     |_|   \n");
    printf("\t\t\t\t                                     __/ |                                                                        \n");
    printf("\t\t\t\t                                    |___/                                                                         \n");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t PRESS ANY KEY \n");
    getch();

}

void exittext()
{


    printf("\n\n\n\t\t\t\t\t\t\tThank you !!!\n");


}
main()
{
    hs = fopen("HistorySell.txt","a");
    hb = fopen("HistoryBuy.txt","a");
    fclose(hs);
    fclose(hb);
    int choice,i,t,cc,v,b=0,s=0,z=0; // t,i choice 1 cc=currencychoice v=BS b=amount of buy his s=amount of sell his
    float m,zx;; //m=money input
    welcomemenu();
    system("cls");
start:
    do
    {
        firstopen();
        t=table();
        menu();
        scanf("%d",&choice);
        system("cls");
        fflush(stdin);
        if(choice==1)
        {
            system("cls");
            for(i=0; i<t; i++)
            {
                printf("%d. %s\n",i+1,A[i].cn.name);
            }
            do
            {
                printf("Choose your currency type according to number above : ");
                scanf("%d",&cc);
                fflush(stdin);
                cc= cc+1;
                cc= cc-1;
            }
            while(cc>t||cc<0);
            if(cc==0)
            {
                system("cls");
                goto start;
            }
            printf("Currency   Buy     Sell\n");
            printf("%-10s %.2f   %.2f\n",A[cc-1].cn.name,A[cc-1].buy,A[cc-1].sell);
            v=BS();
            if(v==1)
            {
                do
                {
                    m=0;
                    printf("Enter money (Baht) : ");
                    scanf("%f",&m);
                    fflush(stdin);
                    m=m+1;
                    m=m-1;
                }
                while(m<=0);
                Buy[cc-1].get = m/A[cc-1].buy;
                Buy[cc-1].getint = (int)(m/A[cc-1].buy);
                Buy[cc-1].change = (int)(m-((int)(m/A[cc-1].buy)*A[cc-1].buy));

                printf("%.2f/%.2f = %.2f\n",m,A[cc-1].buy,Buy[cc-1].get);
                printf("Money get = %.0f %s\n",Buy[cc-1].getint,A[cc-1].cn.name);
                printf("change = %.0f Baht",Buy[cc-1].change);
                Buyprint[b].change= Buy[cc-1].change;
                Buyprint[b].moneybuy=m;
                strcpy(Buyprint[b].cn.name,A[cc-1].cn.name);
                Buyprint[b].get= Buy[cc-1].get;
                Buyprint[b].getint = Buy[cc-1].getint;
                Buyprint[b].rate = A[cc-1].buy;
                hb = fopen("HistoryBuy.txt","a");
                fprintf(hb,"\n%s %.2f %.2f %.2f %.0f %.0f",Buyprint[b].cn.name,Buyprint[b].moneybuy,Buyprint[b].rate,Buyprint[b].get,Buyprint[b].getint,Buyprint[b].change);
                fclose(hb);
                b++;
                m=0;
            }
            else if(v==0)
            {
                do
                {
                    m=0;
                    printf("Enter money %s : ",A[cc-1].cn.name);
                    scanf("%f",&m);
                    fflush(stdin);
                    m=m+1;
                    m=m-1;
                }
                while(m<=0);
                Sell[cc-1].get = A[cc-1].sell*m;
                Sell[cc-1].getint = (int)(A[cc-1].sell*m);
                printf("%.2fx%.2f = %.2f Baht\n",A[cc-1].sell,m,Sell[cc-1].get);
                printf("Money get = %.0f Baht\n",Sell[cc-1].getint);
                Sellprint[s].moneysell=m;
                strcpy(Sellprint[s].cn.name,A[cc-1].cn.name);
                Sellprint[s].get = Sell[cc-1].get;
                Sellprint[s].getint=Sell[cc-1].getint;
                Sellprint[s].rate = A[cc-1].sell;
                hs = fopen("HistorySell.txt","a");
                fprintf(hs,"\n%s %.2f %.2f %.2f %.0f",Sellprint[s].cn.name,Sellprint[s].moneysell,Sellprint[s].rate,Sellprint[s].get,Sellprint[s].getint);
                fclose(hs);
                s++;
                m=0;
            }
            cc=99999;
        }
        if(choice==2)
        {
            system("cls");
            fp = fopen("Exchangerate.txt","r");
            fclose(fp);
            do
            {
                cc=9999;
                for(i=0; i<t; i++)
                {
                    printf("%d. %s\n",i+1,A[i].cn.name);
                }
                printf("Choose which currency type you want to change buy rate (0) to menu : ");
                scanf("%d",&cc);
                fflush(stdin);
                cc=cc+1;
                cc=cc-1;
                system("cls");
                if(cc==0)
                {
                    goto start;
                }
            }
            while(cc!=1&&cc!=2&&cc!=3&&cc!=4&&cc!=5);
            printf("%s %.2f change to?\n",A[cc-1].cn.name,A[cc-1].buy);
            scanf("%f",&A[cc-1].buy);
            fp = fopen("Exchangerate.txt","w");
            for(i=0; i<t; i++)
            {
                fprintf(fp,"\n%s %.2f %.2f",A[i].cn.name,A[i].buy,A[i].sell);
            }
            fclose(fp);

        }
        if(choice==3)
        {
            system("cls");
            do
            {
                cc=9999;
                for(i=0; i<t; i++)
                {
                    printf("%d. %s\n",i+1,A[i].cn.name);
                }
                printf("Choose which currency type you want to change sell rate (0) to menu : ");
                scanf("%d",&cc);
                fflush(stdin);
                cc=cc+1;
                cc=cc-1;
                system("cls");
                if(cc==0)
                {
                    goto start;
                }
            }
            while(cc!=1&&cc!=2&&cc!=3&&cc!=4&&cc!=5);
            printf("%s %.2f change to?\n",A[cc-1].cn.name,A[cc-1].sell);
            scanf("%f",&A[cc-1].sell);
            fp = fopen("Exchangerate.txt","w");
            for(i=0; i<t; i++)
            {
                fprintf(fp,"\n%s %.2f %.2f",A[i].cn.name,A[i].buy,A[i].sell);
            }
            fclose(fp);
        }
        if(choice==4)
        {
            char con1[100];
            do
            {
                printf("Do you want to delete all history Y/N  u have to rewrite : ");
                gets(con1);
                fflush(stdin);
            }
            while(strcmp(con1,"Y")!=0&&strcmp(con1,"N")!=0&&strcmp(con1,"y") != 0 && strcmp(con1,"n") !=0);
            if(strcmp(con1,"Y")==0||strcmp(con1,"y")==0)
            {
                system("cls");
                secondopen();
            }
            else
            {
                system("cls");
                goto start;
            }
        }
        if(choice==5)
        {
            system("cls");
            printbuy();
            printsell();
        }
        if(choice==6)
        {
            char con[100];
            do
            {
                printf("Do you want to delete all history Y/N : ");
                gets(con);
                fflush(stdin);
            }
            while(strcmp(con,"Y")!=0&&strcmp(con,"N")!=0&&strcmp(con,"y") != 0 && strcmp(con,"n") !=0);
            if(strcmp(con,"Y")==0||strcmp(con,"y")==0)
            {
                hb = fopen("HistoryBuy.txt","w");
                hs = fopen("HistorySell.txt","w");
                fclose(hb);
                fclose(hs);
                system("cls");
                printf("\n\t\t\t\tHistory cleared successfully !\n");
            }
            else
            {
                system("cls");
                goto start;
            }
        }
        else if(choice>6)
        {
            goto start;
        }
    }
    while(choice!=0);
    if(choice==0)
    {
        system("cls");
        exittext();
    }
}

