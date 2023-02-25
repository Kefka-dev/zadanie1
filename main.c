#include <stdio.h>
#include <math.h>

int main()
{
    double M, Nr, ir;//vyska hypoteky, splatnost v rokoch, urokova sadzba

    scanf("%lf %lf %lf", &M, &Nr, &ir);
    printf("%.0lf\n", M);
    printf("%.0lf\n", Nr);
    printf("%.2lf\n", ir);

    ir = ir /100;
    double im = ir/12.0, Nm = Nr*12.0;//mesacna urok sadzba, pocet mesiac splacania
    double S= M*(im/(1-pow((1/(1+im)), Nm)));//fixna mesacna splatka
    
    printf("%.2lf\n", S);

    double Rk, Mk, Dk = M, ZaplatenyUrok = 0; //Urok, Umor, Nesplateny dlh
    int rok=1, mesiac=1;
    for (int i = 0; i <Nm; i++)
    {
        Rk = im*Dk;
        Mk = S-Rk;
        if (i == Nm-1)
        {
            Dk = 0;
        }
        else
        {
            Dk = Dk - Mk;
        }
        
        printf("%-2d %-2d %-10.2lf %-10.2lf %-10.2lf\n", rok, mesiac, Rk, Mk, Dk);
        ZaplatenyUrok = ZaplatenyUrok + Rk;
        mesiac++;
        if (mesiac > 12)
        {
            mesiac = 1;
            rok++;
        }
    }
    printf("%-.2lf\n", ZaplatenyUrok);
    return 0;
}
