class Solution {
public:
string addStrings(string num1, string num2) {
reverse(num1.begin(),num1.end());
reverse(num2.begin(),num2.end());
int m=num1.size();
int n=num2.size();
int i=0,j=0,carry=0;
string res="";
while(i<m && j<n)
{
int sum=num1[i]-'0'+num2[j]-'0'+carry;
if(sum>9)carry=1;
else carry=0;
char ch=sum%10+'0';
res=res+ch;
i++;
j++;
}
while(i<m)
{
int sum=num1[i]-'0'+carry;
if(sum>9) carry=1;
else carry=0;
char ch=sum%10+'0';
res=res+ch;
i++;
}
while(j<n)
{
int sum=num2[j]-'0'+carry;
if(sum>9) carry=1;
else carry=0;
char ch=sum%10+'0';
res=res+ch;
j++;
}
if(carry==1) res=res+'1';
reverse(res.begin(),res.end());
return res;
}
};