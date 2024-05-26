#include <iostream>
#include <math.h>
using namespace std;
double aasin (double a)//采用一个函数直接输出结果而不需要转换
{
    return(asin(a)*180/3.1415926);
}
int main ()
{
    double t1,t2,t0,tk,tg,tp,phi,Q0;//要输入的数据
    double k=800,rou=998.68,Cp=4.186,lamuda=0.594,eta=10.01*pow(10,-4);
    double pai=3.1415926,d0=0.025,d=0.021,u=1.2,l=6,a=32,e=113,b=23,P=95.57;
    double sigma=13230,puxi=0.65,C=0.5,Lfact=24,g=9.81,Z=4,H2Olamda=0.593;
    double DeltaT=7.5,NH3T=21.25,Ai=153.51,Ao=182.75,Am=167.71;
    double NH3rou=608,NH3lamda=0.48,NH3eta=1.32*pow(10,-4),NH3r=1181.25;//部分常数与变量直接进行初始化
    cin>>t1>>t2>>t0>>tk>>tg>>tp>>phi>>Q0;//数据输入
    double Ql;//定义变量
    Ql=Q0*phi;//计算Ql
    double avgQl=Ql/3;//计算并联后设备负载
    cout<<"Q1="<<Ql<<"kW"<<endl;//总负载
    cout<<"avgQl="<<avgQl<<"kW"<<endl;//并联后每台设备的负载
    double deltaT=(t2-t1)/log((tk-t1)/(tk-t2));//计算温差
    cout<<"deltaT="<<deltaT<<"°C"<<endl;//输出温差
    double F=avgQl*1000/k/deltaT;//进行单位转化后计算
    cout<<"F="<<F<<"㎡"<<endl;//输出F
    double t=(t1+t2)/2;//计算定性水温度
    cout<<"t="<<t<<endl;//输出定性水结果
    double M=avgQl/Cp/(t2-t1);//计算质量流量
    cout<<"M="<<M<<"kg/s"<<endl;//输出质量流量
    double V=M/rou;//计算体积流量
    cout<<"V="<<V<<"m³/s"<<endl;//输出体积流量
    int n=int((V/pai*4/pow(d,2)/u)+1);//计算管数的小数，在输出中对其进行向上取整
    cout<<"n="<<n<<endl;//输出管数，在输出时进行向上取整
    double L=F/n/pai/d;//计算管道长度L；
    cout<<"L="<<L<<"m"<<endl;//输出管道长度L
    int m=int((L/l)+1);//计算管程数
    cout<<"m="<<m<<endl;//输出管程数
    int NT=m*n;//计算总管数
    cout<<"NT="<<NT<<endl;//输出总管数
    int alpha=(30-aasin(d0*1000/2/a));//换算单位，计算偏转角
    cout<<"α="<<alpha<<"°"<<endl;//输出偏转角
    double D=int((a*(b-1)+2*e)/100+1)*100;//计算内径
    cout<<"D="<<D<<"mm"<<endl;//输出内径
    double s=P*D/10/(2*sigma*puxi-P)+C;//计算壁厚
    s*=10;//转换为mm
    if (s<12)//判断其是否符合要求
    {
        s=12;
    }
    cout<<"s="<<s<<"mm"<<endl;//输出壁厚
    int npai=NT/m;//计算平均管数
    cout<<"n'="<<npai<<endl;//输出平均管数
    double Apai=npai*Lfact*pai*d;//计算实际传热面积
    cout<<"A'="<<Apai<<"㎡"<<endl;//输出实际传热面积
    double upai=V/pai*4/pow(d,2)/npai;//计算实际流速
    cout<<"u'="<<upai<<"m/s"<<endl;//输出实际流速
    double Re=d*u*rou/eta;//计算雷诺数
    if (Re>10000)//判断是否通过
    {
        cout<<"Re="<<Re<<",通过要求"<<endl;
    }   
    else
    {
        cout<<"Re="<<Re<<",未通过要求"<<endl;
    }
    double Hf=(0.22*pow(Re,-0.2)*6/d*pow(u,2)/2/g*Z)+4*Z*pow(u,2)/2/g;//计算流动阻力
    cout<<"Hf="<<Hf<<"mH2O"<<endl;//输出流动阻力
    double alphai=0.023*(H2Olamda/d)*pow(Re,0.8)*pow((Cp*1000*eta/H2Olamda),0.4);//计算传热系数αi
    cout<<"alphai="<<alphai<<endl;//输出传热系数αi
    double alphao=0.725*pow((pow(NH3lamda,3)*pow(NH3rou,2)*g*NH3r*1000/NH3eta/d0/12/DeltaT),0.25);
    //计算冷凝膜系数
    cout<<"alphao="<<alphao<<"W/㎡·K"<<endl;//输出冷凝膜系数
    double Ki=pow((1/4581.78+0.0005+(0.002*Ao/45.4/Am)+(0.18*pow(10,-3)+1/4704.88)*Ao/Ai),-1);
    cout<<"ki="<<Ki<<endl;
    
}