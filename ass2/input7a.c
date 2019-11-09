int main()
{
int a =1;
int b =1; int i=0;
int n;
int c=0;

read(n); if(n < 1)
print(0);
else
{
while(i < n)
{
c = a + b;
print(c);
b = a;
a = c;
i++; 
}
}
}
