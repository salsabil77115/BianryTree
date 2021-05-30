#include <iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<string.h>
using namespace std;
class BinaryTree{
struct node{
int item;
node*left;
node*right;

node(int item){

this->item=item;
this->right=0;
this->left=0;
}
};
int length;
node*root;
public:
vector<int>num;

    BinaryTree(){
        length=0;
        root=NULL;
    }
    bool isEmpty(){return root==NULL;}

void insertnode(int item){
    node*cur=root;
node *pre=0;
num.push_back(item);
    while(cur!=0){
            pre=cur;
        if(item<cur->item){
            cur=cur->left;

        }
        else{cur=cur->right;}

    }
    if(isEmpty()){
    root=new node(item);
    }
    else if(item<pre->item){
          pre->left=new node(item);
        }
        else{
            pre->right=new node(item);
        }
        length++;
    }



void delete1(int item){
node*cur=root;
node*pre;
    int x=0;

for(int i=0;i<num.size();i++){
        if(item==num[i]){x=i;}

}
if(x==0){cout<<"not found"<<endl;}
else{
        num.erase(num.begin()+x);
while(cur!=0&&cur->item!=item){
        pre=cur;
 if(cur->item<item){
    cur=cur->right;
 }
 else{cur=cur->left;}

}

if(cur->left==0&&cur->right==0){
if(pre->item>item){pre->left=0;}
else{pre->right=0;}
delete cur;}

else if(cur->left==0){
if(pre->item>item){
    pre->left=cur->right;
}
else{pre->right=cur->right;}
delete cur;
}
else{
    pre=cur;
    int count=0;

    if(item<root->item){
    while(pre->right!=0)
    {
    pre=pre->right;
    }

count++;
 }
    else{
    while(pre->left!=0)
    {
    pre=pre->left;
    }

    count=0;
    }

cur->item=pre->item;
if(count!=0){cur->right=0;}
else{cur->left=0;}
delete pre;
length--;}
}
}


  int height(node*no){
  if(no==NULL){return false;}
  return 1+max(height(no->left),height(no->right));}

int max(int a,int b){

return(a>=b)?a:b;

}
bool isbalacne(node*root){
if(root==0){return true;}
int Lh;
int rh;
Lh=height(root->left);
rh=height(root->right);
if(abs(Lh-rh)<=1&&isbalacne(root->left)&&isbalacne(root->right)){return true;}

return false;}


void is_balacne(){cout<<isbalacne(root);}

void printRange(int x,int y){
    node*cur=root;
    node*pre=0;
        if(x<root->item&&y<=root->item){
            if(y==root->item){  cout<<root->item<<" ";}
                pre=cur=root->left;
    while( cur->left!=0){

    if(x<=cur->item&&y>=cur->item)
               {cout<<cur->item<< " ";}
            cur=cur->left;}
                if(x<=cur->item&&y>=cur->item){

cout<<cur->item<< " ";}
while(pre->right!=0){
                    pre=pre->right;

        if (x<=pre->item&&y>=pre->item){   cout<<pre->item<< " ";}

        }
        }
      else if(x>=root->item&&y>root->item){
            if(x==root->item){   cout<<root->item<<" ";}

        pre=cur=root->right;
                   while( cur->left!=0){

    if(x<=cur->item&&y>=cur->item)
               {cout<<cur->item<< " ";}
            cur=cur->left;}
                if(x<=cur->item&&y>=cur->item){

cout<<cur->item<< " ";}
while(pre->right!=0){
                    pre=pre->right;

        if (x<=pre->item&&y>=pre->item){   cout<<pre->item<< " ";}

}

        }
       else if(root->item>=x&&root->item<=y){

                pre=cur=root->right;
                while(cur->left!=0){
    if(x<=cur->item&&y>=cur->item){
                cout<<cur->item<< " ";}
cur=cur->left;
        }
    if(x<=cur->item&&y>=cur->item){

cout<<cur->item<< " ";}

        while(pre->right!=0){
            pre=pre->right;
    if(x<=pre->item&&y>=pre->item){
                cout<<pre->item<< " ";}
        }

        pre=cur=root->left;
             while(cur->left!=0){
    if(x<=cur->item&&y>=cur->item){
                cout<<cur->item<< " ";}
cur=cur->left;
        }
            if(x<=cur->item&&y>=cur->item){

cout<<cur->item<< " ";}

             while(pre->right!=0){
                 pre=pre->right;

    if(x<=pre->item&&y>=pre->item){
                cout<<pre->item<< " ";}
        }
       }

        else{cout<<"not found"<<endl;}


}
void is_subtree(BinaryTree t1,BinaryTree t2){

node*p1=t1.root;
node*p2=t2.root;
while(p1!=0){

    if(p1->item<p2->item){p1=p1->right;}
      else if(p1->item>p2->item){p1=p1->left;}
    else if(p1->item==p2->item){break;}
    else{
    break;}

}
node*cur1=p1;
node*cur2=p2;
int c=1;

while(p1->right!=0&&p2->right!=0){
if(c==0){break;}
else{
    p1=p1->right;
    p2=p2->right;
    if(p1->item==p2->item){c++;}
    else{c=0;
    break;}
    }
}
 while(cur1->left!=0&&cur2->left!=0){
    if(c==0){break;}
    else{
    cur1=cur1->left;
    cur2=cur2->left;
    if(cur1->item==cur2->item){c++;}
    else{
    c=0;
    break;}
    }
}
     if(c==0){cout<<"false";}
     else{cout<<"true";}
     }

};
int main()
{
    BinaryTree x;
    BinaryTree x1;

x.insertnode(6);
x.insertnode(4);
x.insertnode(10);
x.insertnode(9);
x.insertnode(12);
x.insertnode(2);
x.insertnode(5);
x1.insertnode(10);
x1.insertnode(9);
x1.insertnode(12);


x.delete1(4);
cout<<endl;
x.is_subtree(x,x1);
cout<<endl;
x.printRange(2,10);
cout<<endl;
x.is_balacne();
cout<<endl;
x1.is_balacne();

    return 0;
}
