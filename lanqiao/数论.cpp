//最小公倍数
int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
//最大公约数
int lcm(int a, int b) { return a * b / gcd(a, b); }