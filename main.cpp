#include <iostream>
#include <fstream>
#include <string>

using namespace std;



unsigned char regel[6][6] = {
{0, 0, 0, 0, 4, 5},
{0, 0, 0, 3, 0, 0},
{0, 0, 6, 0, 1, 3},
{4, 1, 0, 6, 0, 0},
{0, 0, 4, 0, 0, 0},
{2, 6, 0, 0, 0, 0}};
int i = 0,j = 0, x = 0, y = 0, p = 0, temp =0;
string buffer;
char *line;
   int een[6][6], twee[6][6], drie[6][6], vier[6][6], vijf[6][6], zes[6][6];
int q[24] = {0, 2, 0, 3, 0, 2, 3, 6, 2, 4, 0, 3, 2, 4, 3, 6, 4, 6, 0, 3, 4, 6, 3, 6};

int nul_maker() //bezetten plekken leeg maken
{
     switch(regel[i][j]){
                case 0:
                 //   printf("NULL NIKS DOEN!\nregel[%d][%d] = %d\n",i,j,regel[i][j]);
                break;

                case 1:
                    twee[i][j] = 0;
                    drie[i][j] = 0;
                    vier[i][j] = 0;
                    vijf[i][j] = 0;
                    zes[i][j]  = 0;
                break;

                case 2:
                    een[i][j]  = 0;
                    drie[i][j] = 0;
                    vier[i][j] = 0;
                    vijf[i][j] = 0;
                    zes[i][j]  = 0;
                break;

                case 3:
                    een[i][j]  = 0;
                    twee[i][j] = 0;
                    vier[i][j] = 0;
                    vijf[i][j] = 0;
                    zes[i][j]  = 0;
                break;

                case 4:
                    een[i][j]  = 0;
                    twee[i][j] = 0;
                    drie[i][j] = 0;
                    vijf[i][j] = 0;
                    zes[i][j]  = 0;
                break;

                case 5:
                    een[i][j]  = 0;
                    twee[i][j] = 0;
                    drie[i][j] = 0;
                    vier[i][j] = 0;
                    zes[i][j]  = 0;
                break;

                case 6:
                    een[i][j]  = 0;
                    twee[i][j] = 0;
                    drie[i][j] = 0;
                    vier[i][j] = 0;
                    vijf[i][j] = 0;
                break;

                default:
                    printf("Hier zouden we nooit mogen komen! ABORT ABORT!\nregel[%d][%d] = %d\n",i,j,regel[i][j]);
     }

return 0;
}

int nul_maker2(int temp) //bezetten hokjes leeg maken.
{

    for(x=q[p]; x<q[p+1]; x++)
    {
        for(y=q[p+2]; y<q[p+3]; y++)
            {
                switch(temp)
                   {
                    case 1:
                    een[x][y]  = 0;
                    break;

                    case 2:
                    twee[x][y] = 0;
                    break;

                    case 3:
                    drie[x][y] = 0;
                    break;

                    case 4:
                    vier[x][y] = 0;
                    break;

                    case 5:
                    vijf[x][y] = 0;
                    break;

                    case 6:
                    zes[x][y]  = 0;
                    break;
                    }
            }
    }

    //printf("ik ben aan geroepen!\n");
return 0;
}

int nul_maker3(int m, int n, int temp) // rijen en kolomen leeg maken
{
    for(x=0; x<6; x++)
    {
        switch(temp)
                   {
                    case 1:
                    een[x][n] = 0;
                    een[m][x] = 0;
                    break;

                    case 2:
                    twee[x][n] = 0;
                    twee[m][x] = 0;
                    break;

                    case 3:
                    drie[x][n] = 0;
                    drie[m][x] = 0;
                    break;

                    case 4:
                    vier[x][n] = 0;
                    vier[m][x] = 0;
                    break;

                    case 5:
                    vijf[x][n] = 0;
                    vijf[m][x] = 0;
                    break;

                    case 6:
                    zes[x][n] = 0;
                    zes[m][x] = 0;
                    break;
                    }
    }
return 0;
}

int chekker(int m, int n, int buff[6][6]) //controleer of getal in desbetreffend hokje voorkomt.
{
 //   printf(" [%d,%d]\n", m, n);

    int fout = 0;
    for(x=0; x<6; x++)
    {
        if(buff[x][n] != 0 || buff[m][x] != 0)
         {
             fout++;
         }
    }
//    printf("fouten na rij en kolom check: %d \n",fout);
    //hokjes check
    if(fout != 1) //als er conclickten zijn gevonden in een rij of kolom kijken of getal in hokje enige optie is
    {
        //getal m en n omzetten naar hun hokje.

        fout = 0;

        if(m == 0 || m == 1){
        if(n<3) { p = 0; }
        else { p = 4;    }
        }

        if(m == 2 || m == 3){
        if(n<3) {p = 8;  }
        else {p = 12;    }
        }

        if(m == 4 || m == 5){
        if(n<3) {p = 16;  }
        else {p = 20;     }
        }

            for(x=q[p]; x<q[p+1]; x++)
            {
                for(y=q[p+2]; y<q[p+3]; y++)
                {
                    if(buff[x][y] != 0)
                     {
                         fout++;
                     }
                }
            }

    }


//printf("fouten na hokje check: %d \n",fout);

//als blijkt dat het onderzockte getal de enige mogelijkheid is, dan is fout 1.
return fout;
}

int sommen(int n) //constroleerd welk getal nog mist in rij of kolom en vult deze in.
{
int aantal = 0, temp = 0, leeg = 0;
    for(j=0; j<6; j++)
    {
        if(regel[j][n] == 0)
        {
            aantal++;
            leeg = j;
        }
        temp = temp + regel[j][n];
    }

    if(aantal == 1)
    {
        regel[leeg][n] = 21 - temp;
    }

    aantal = 0;
    temp = 0;
    leeg = 0;

    for(j=0; j<6; j++)
    {
        if(regel[n][j] == 0)
        {
            aantal++;
        }
        temp = temp + regel[n][j];
    }

    if(aantal == 1)
    {
        regel[n][leeg] = 21 - temp;
    }
return 0;
}

int slimmerik(int buff[6][6]) //slim trukje
{

    for(i=0; i<6; i++)
    {
       //switch even en oneven.
        switch(i)
        {
        case 0: case 2: case 4:
        if(buff[i][0] + buff[i][1] + buff[i][2] == 0) // als even dan is bovenste rij.
        {
            buff[i+1][3] = 0;
            buff[i+1][4] = 0;
            buff[i+1][5] = 0;
        //printf("in regel %d en hokje links zijn er geen getallen gedecteerd\n",i);
        }
        else if(buff[i][3] + buff[i][4] + buff[i][5] == 0)
        {
            buff[i+1][0] = 0;
            buff[i+1][1] = 0;
            buff[i+1][2] = 0;
        //printf("in regel %d en hokje rechts zijn er geen getallen gedecteerd\n",i);
        }

        break;

        case 1: case 3: case 5:
        if(buff[i][0] + buff[i][1] + buff[i][2] == 0) // als even dan is bovenste rij.
        {
            buff[i-1][3] = 0;
            buff[i-1][4] = 0;
            buff[i-1][5] = 0;
        //printf("in regel %d en hokje links zijn er geen getallen gedecteerd\n",i);
        }
        else if(buff[i][3] + buff[i][4] + buff[i][5] == 0)
        {
            buff[i-1][0] = 0;
            buff[i-1][1] = 0;
            buff[i-1][2] = 0;
        //printf("in regel %d en hokje rechts zijn er geen getallen gedecteerd\n",i);
        }
        break;
        }
    }
/*
for(i=0; i<6; i++)
    {
            for(j=0; j<6; j++)
            {
               printf(" %i ", twee[i][j]);
            }
        printf("\n");
    }

printf("\n");
*/
return buff[6][6];
}

int uitslag() //bekijkt of de sudocu al is opgelost, zo ja, dan wordt het oplossen gestop.
{
int temp = 0;
   for(i = 0;i < 6;i++)
    {
        for(j = 0;j < 6;j++)
          {
            if(regel[i][j] == 0) temp++;
          }

    }

if(temp != 0) return 1;
else { printf("done!!\n"); return 100;}
}


int uitprinter0()
{
   for(i = 0;i < 6;i++)
    {
        for(j = 0;j < 6;j++)
          {
            printf(" %d ",regel[i][j]);
          }
          printf("\n");
    }
printf("\n");
return 0;
}

int uitprinter1()
{
    for(i=0; i<6; i++)
    {
            for(j=0; j<6; j++)
            {
               printf(" %i ", een[i][j]);
            }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<6; i++)
    {
            for(j=0; j<6; j++)
            {
               printf(" %i ", twee[i][j]);
            }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<6; i++)
    {
            for(j=0; j<6; j++)
            {
               printf(" %i ", drie[i][j]);
            }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<6; i++)
    {
            for(j=0; j<6; j++)
            {
               printf(" %i ", vier[i][j]);
            }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<6; i++)
    {
            for(j=0; j<6; j++)
            {
               printf(" %i ", vijf[i][j]);
            }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<6; i++)
    {
            for(j=0; j<6; j++)
            {
               printf(" %i ", zes[i][j]);
            }
        printf("\n");
    }
printf("\n");
return 0;
}

int uitprinter2()
{
    for(i=0; i<6; i++)
    {
            for(j=0; j<6; j++)
            {
               printf(" %i ", twee[i][j]);
            }
        printf("\n");
    }

printf("\n");
return 0;
}

int uitprinter7()
{
    for(i=0; i<6; i++)
    {
            for(j=0; j<6; j++)
            {
               printf(" %i ", een[i][j]);
            }

            printf("|");

            for(j=0; j<6; j++)
            {
               printf(" %i ", twee[i][j]);
            }

            printf("|");

            for(j=0; j<6; j++)
            {
               printf(" %i ", drie[i][j]);
            }

            printf("|");

            for(j=0; j<6; j++)
            {
               printf(" %i ", vier[i][j]);
            }

            printf("|");

            for(j=0; j<6; j++)
            {
               printf(" %i ", vijf[i][j]);
            }

            printf("|");

            for(j=0; j<6; j++)
            {
               printf(" %i ", zes[i][j]);
            }
        printf("\n");
    }

printf("\n");
return 0;
}

int main()
{

//laten zien van orgineel
uitprinter0();

//eerst een hoop geheuger vol smeren.
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            een[i][j]  = 1;
            twee[i][j] = 2;
            drie[i][j] = 3;
            vier[i][j] = 4;
            vijf[i][j] = 5;
            zes[i][j]  = 6;
        }
    }

int var = 0, count = 0;
while(count < 30) // aantal oplos rondes te houden.
{
//controle op al bezetten plaatsen en discrimineren
    for(i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
               nul_maker();
            }
        }



//hokjes chekken.
    for(p=0; p<24; p=p+4)
    {

        for(i=q[p]; i<q[p+1]; i++)
        {
            for(j=q[p+2]; j<q[p+3]; j++)
            {
                    if(regel[i][j] != 0)
                    {
                        nul_maker2(regel[i][j]);
                        switch(regel[i][j])
                           {
                            case 1:
                            een[i][j]  = 1;
                            break;

                            case 2:
                            twee[i][j] = 2;
                            break;

                            case 3:
                            drie[i][j] = 3;
                            break;

                            case 4:
                            vier[i][j] = 4;
                            break;

                            case 5:
                            vijf[i][j] = 5;
                            break;

                            case 6:
                            zes[i][j]  = 6;
                            break;
                            }

                    }
            }
        }
    }

//rijen en kolomen discrimineren
for(i=0; i<6; i++)
        {
            for(j=0; j<6; j++)
            {
               if(regel[i][j] != 0)
               {
                 nul_maker3(i,j,regel[i][j]);
                 switch(regel[i][j])
                           {
                            case 1:
                            een[i][j]  = 1;
                            break;

                            case 2:
                            twee[i][j] = 2;
                            break;

                            case 3:
                            drie[i][j] = 3;
                            break;

                            case 4:
                            vier[i][j] = 4;
                            break;

                            case 5:
                            vijf[i][j] = 5;
                            break;

                            case 6:
                            zes[i][j]  = 6;
                            break;
                            }
               }

            }
        }

//sommen van rijen en kolomen controleren
for(i=0; i<6; i++)
{
  //  sommen(i);
}


// uitprinten van resultaten
//uitprinter7();

//nu alle mogelijke plekken van elk cijfer bepaalt is, moet nu gecontroleerd worden waar er nog een cijfer niet anders kan en dan vast gelegt worden.

   // printf("oplossen gestart\n\n");
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
                if(een[i][j]  == 1)
                {
                    var = chekker(i, j, een);   // chekker controleer of er andere mogelijkheden zijn voor dit getal.
                if(var == 1)
                {
                    regel[i][j] = 1;
                   // printf("ikke schrijf 1 naar regel op  [%d, %d] \n",i,j);
                    var = 0;
                }
              //  else printf("ikke mag niets schrijfen naar regel\n");
                }

                if(twee[i][j]  == 2)
                {
                    var = chekker(i, j, twee);   // chekker controleer of er andere mogelijkheden zijn voor dit getal.
                if(var == 1)
                {
                    regel[i][j] = 2;
              //      printf("ikke schrijf 2 naar regel op  [%d, %d] \n",i,j);
                    var = 0;
                }
             //   else printf("ikke mag niets schrijfen naar regel\n");
                }

                if(drie[i][j]  == 3)
                {
                    var = chekker(i, j, drie);   // chekker controleer of er andere mogelijkheden zijn voor dit getal.
                if(var == 1)
                {
                    regel[i][j] = 3;
             //       printf("ikke schrijf 3 naar regel op  [%d, %d] \n",i,j);
                    var = 0;
                }
             //   else printf("ikke mag niets schrijfen naar regel\n");
                }

                if(vier[i][j]  == 4)
                {
                    var = chekker(i, j, vier);   // chekker controleer of er andere mogelijkheden zijn voor dit getal.
                if(var == 1)
                {
                    regel[i][j] = 4;
            //        printf("ikke schrijf 4 naar regel op  [%d, %d] \n",i,j);
                    var = 0;
                }
             //   else printf("ikke mag niets schrijfen naar regel\n");
                }

                if(vijf[i][j]  == 5)
                {
                    var = chekker(i, j, vijf);   // chekker controleer of er andere mogelijkheden zijn voor dit getal.
                if(var == 1)
                {
                    regel[i][j] = 5;
              //      printf("ikke schrijf 5 naar regel op  [%d, %d] \n",i,j);
                    var = 0;
                }
              //  else printf("ikke mag niets schrijfen naar regel\n");
                }

                if(zes[i][j]  == 6)
                {
                    var = chekker(i, j, zes);   // chekker controleer of er andere mogelijkheden zijn voor dit getal.
                if(var == 1)
                {
                    regel[i][j] = 6;
              //      printf("ikke schrijf 6 naar regel op  [%d, %d] \n",i,j);
                    var = 0;
                }
             //   else printf("ikke mag niets schrijfen naar regel\n");
                }
        }
    }

//aan roepen van slimme truck alleen rijen.
uitprinter7();

//slimmerik(een);
twee[6][6] = slimmerik(twee);
//slimmerik(drie);
//slimmerik(vier);
//slimmerik(vijf);
//slimmerik(zes);

count = count + uitslag();
}

uitprinter0();

return 0;
    }

