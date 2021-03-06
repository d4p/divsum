#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define NOT_SPOJ

using namespace std;
#ifdef NOT_SPOJ
FILE *f;
#endif

int C[500001];

char outBuf[9*200000];
int outBufIndex = 0;


inline void print(int n){
    if (n == 0){
        outBuf[outBufIndex] = '0';
        outBufIndex++;
        outBuf[outBufIndex] = '\n';
        outBufIndex++;
    } else
    {
        char buf[11];
        buf[10] = '\n';
        int i = 9;
        while (n)
        {
            buf[i--] = n % 10 + '0';
            n /= 10;
        }
        while (buf[i] != '\n'){
            //putchar(buf[++i]);
            outBuf[outBufIndex] = buf[++i];
            outBufIndex++;
        }
    }
}

inline int find_div_sqrt_sum(int number){
    if (C[number] != 0){
        print(C[number]);
        return 0;
    }

    int sum = 1;
    double gg=sqrt(number);
    for(int i=2; i<=(gg); i++) {
        if(number % i == 0){
            sum+=i;
            if (number/i > gg)
                sum+= number/i;
        }
    }
    C[number] = sum;
    //printf("%d\n", sum);
    //printf("C[%d]=%d;\n", number,sum);
    print(sum);

}
inline int isPerfectSquare(int n)
{
  if (n < 0)
    return false;

  switch((int)(n & 0x3F))
  {
  case 0x00: case 0x01: case 0x04: case 0x09: case 0x10: case 0x11:
  case 0x19: case 0x21: case 0x24: case 0x29: case 0x31: case 0x39:
    long sqrt;
    /*
    if(n < 410881L)
    {
      //John Carmack hack, converted to Java.
      // See: http://www.codemaestro.com/reviews/9
      int i;
      float x2, y;

      x2 = n * 0.5F;
      y  = n;
      i  = Float.floatToRawIntBits(y);
      i  = 0x5f3759df - ( i >> 1 );
      y  = Float.intBitsToFloat(i);
      y  = y * ( 1.5F - ( x2 * y * y ) );

      sqrt = (long)(1.0F/y);
    }
    else
    {
    */
      //Carmack hack gives incorrect answer for n >= 410881.
      sqrt = sqrt(n);
  //  }
    return sqrt*sqrt == n;

  default:
    return false;
  }
}

inline find_div_fermat(int number){
    if (number % 2 == 0){//even

    } else { //odd
        int a = ceil(sqrt(number));
        int b2 = a*a - number;
        int b2square = b2*b2;

        while (!isPerfectSquare(b2)){
            a=a++;
            b2=a*a - number;
        }
        return a- sqrt(b2);
    }
}

int main1(int argc, char *argv[])
{
//    for(int i = 0;i<=500000;i++)
//        C[i] = 0;
    //initC();
    int count = 0;
#ifdef NOT_SPOJ
    f = fopen("input2.txt","r");
    fscanf(f,"%d\n", &count);
#else
    scanf("%d\n", &count);
#endif
    while (count--){
        int number = 0;
#ifdef NOT_SPOJ
        fscanf(f,"%d\n",&number);
#else
//        scanf("%d\n",&number);
        char c = 0;

        c = getchar();
        while (c != '\n' && c != EOF){
            number = number *10 + c - '0';
            c = getchar();
        }
        if (number != 0 && c == EOF){
            write(STDOUT_FILENO,outBuf,outBufIndex);
            fflush(stdout);

            return 0;
        }

#endif
        if(number == 1)
            print(0);

        else{
            find_div_sqrt_sum(number);
        }
    }
    write(STDOUT_FILENO,outBuf,outBufIndex);
    fflush(stdout);
    return 0;
}

int main(){
    for(int i = 1;i<=250000;i++){
        find_div_sqrt_sum(i);
    }
    write(STDOUT_FILENO,outBuf,outBufIndex);
    fflush(stdout);
    outBufIndex = 0; //reset the output buffer
    for(int i = 250001;i<=500000;i++){
        find_div_sqrt_sum(i);
    }
    write(STDOUT_FILENO,outBuf,outBufIndex);
    fflush(stdout);
    return 0;
}


void initC(){
    C[500000] = 730453;
    C[499999]=20225;
    C[499998]=508002;
    C[499997]=21763;
    C[499996]=518252;
    C[499995]=391077;
    C[499994]=318214;
    C[499993]=38475;
    C[499992]=770088;
    C[499991]=6409;
    C[499990]=400010;
    C[499989]=289131;
    C[499988]=380332;
    C[499987]=29429;
    C[499986]=640494;
    C[499985]=135523;
    C[499984]=468766;
    C[499983]=239217;
    C[499982]=370930;
    C[499981]=13551;
    C[499980]=1010004;
    C[499979]=1;
    C[499978]=249992;
    C[499977]=233067;
    C[499976]=437494;
    C[499975]=208809;
    C[499974]=543738;
    C[499973]=1;
    C[499972]=462682;
    C[499971]=166661;
    C[499970]=461554;
    C[499969]=1;
    C[499968]=1200640;
    C[499967]=38473;
    C[499966]=306434;
    C[499965]=300003;
    C[499964]=374980;
    C[499963]=2165;
    C[499962]=510918;
    C[499961]=142087;
    C[499960]=666440;
    C[499959]=240761;
    C[499958]=252994;
    C[499957]=1;
    C[499956]=687468;
    C[499955]=99997;
    C[499954]=459662;
    C[499953]=205935;
    C[499952]=468736;
    C[499951]=21761;
    C[499950]=979866;
    C[499949]=9487;
    C[499948]=374968;
    C[499947]=320853;
    C[499946]=249976;
    C[499945]=99995;
    C[499944]=785976;
    C[499943]=1;
    C[499942]=249974;
    C[499941]=277927;
    C[499940]=700252;
    C[499939]=57629;
    C[499938]=511422;
    C[499937]=16159;
    C[499936]=543344;
    C[499935]=299985;
    C[499934]=249970;
    C[499933]=71427;
    C[499932]=807836;
    C[499931]=17269;
    C[499930]=399962;
    C[499929]=166647;
    C[499928]=709672;
    C[499927]=1;
    C[499926]=642858;
    C[499925]=120013;
    C[499924]=374950;
    C[499923]=222201;
    C[499922]=254650;
    C[499921]=3231;
    C[499920]=1050576;
    C[499919]=105169;
    C[499918]=267530;
    C[499917]=227283;
    C[499916]=374944;
    C[499915]=146213;
    C[499914]=583272;
    C[499913]=21727;
    C[499912]=594488;
    C[499911]=176313;
    C[499910]=399946;
    C[499909]=34331;
    C[499908]=666572;
    C[499907]=24493;
    C[499906]=345662;
    C[499905]=561855;
    C[499904]=515080;
    C[499903]=1;
    C[499902]=685938;
    C[499901]=1699;
    C[499900]=585100;
    C[499899]=170133;
    C[499898]=372544;
    C[499897]=1;
    C[499896]=890064;
    C[499895]=169705;
    C[499894]=249950;
    C[499893]=166635;
    C[499892]=393868;
    C[499891]=71421;
    C[499890]=764430;
    C[499889]=38467;
    C[499888]=479712;
    C[499887]=233833;
    C[499886]=249946;
    C[499885]=135371;
    C[499884]=957012;
    C[499883]=1;
    C[499882]=282614;
    C[499881]=166631;
    C[499880]=624940;
    C[499879]=1;
    C[499878]=611082;
    C[499877]=71419;
    C[499876]=442296;
    C[499875]=378717;
    C[499874]=257146;
    C[499873]=64607;
    C[499872]=854880;
    C[499871]=26329;
    C[499870]=561698;
    C[499869]=222177;
    C[499868]=426484;
    C[499867]=1613;
    C[499866]=499878;
    C[499865]=103855;
    C[499864]=437396;
    C[499863]=320873;
    C[499862]=318130;
    C[499861]=1911;
    C[499860]=1016928;
    C[499859]=29293;
    C[499858]=253370;
    C[499857]=166623;
    C[499856]=607216;
    C[499855]=99977;
    C[499854]=506994;
    C[499853]=1;
    C[499852]=421068;
}
