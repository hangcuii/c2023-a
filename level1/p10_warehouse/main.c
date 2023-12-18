#include<stdio.h>
#include<string.h>
int quan_goods=0;
int  temp=0;
struct goods
{ char name[20];
    int quantity;
};
typedef struct goods goods;
goods warehouse[10];
void printware()
{printf("goods    quantiry\n");
    for(int j=0;j<quan_goods;j++)
    {printf("%s        %d\n",warehouse[j].name,warehouse[j].quantity);
    }

}
void in_()
{scanf("%s",(warehouse[quan_goods].name));
    scanf("%d",&(warehouse[quan_goods].quantity));
    quan_goods++;
}


void out_()
{ char nam[20];
    printf("name");
scanf("%s",&nam);
for(int i=0;i<=quan_goods;i++)
{if (strcmp(warehouse[i].name, nam) == 0)
    {for(int j=i;j<=quan_goods;j++)
        {warehouse[i]=warehouse[i+1];

        }
    quan_goods--;
    }

}



}
void loadfile() {
    FILE* fp = fopen("C:\\Users\\cuihang\\CLionProjects\\c2023-a\\level1\\p10_warehouse\\warehouse.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    fscanf(fp, "%d", &quan_goods);
    fread(warehouse, sizeof(goods), quan_goods, fp);


    fclose(fp);
}

void savefile() {
    FILE* fp = fopen("C:\\Users\\cuihang\\CLionProjects\\c2023-a\\level1\\p10_warehouse\\warehouse.txt", "w"
                                                                                                         "");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    fprintf(fp, "%d", quan_goods);
    fwrite(warehouse, sizeof(goods), quan_goods, fp);


    fclose(fp);
}
int main() {
    printf("1.Displays a list of inventory\n 2.put in storage\n 3.Delivery from storage\n 4.quit");
    loadfile();
    int exit=0;
    while (exit != 1)
    {
    int order;
    scanf("%d",&order);
switch(order) {
    case 1:
    { printware();
        break;
    }
    case 2:
    {in_();
        break;
    }
    case 3:
    {out_();
        break;
    }
    case 4:
    {exit=1;
        savefile();
        break;
    }


}
}




return 0;

}