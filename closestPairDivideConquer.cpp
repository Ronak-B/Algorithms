#include<iostream>
#include<math.h>
using namespace std;

struct Point
{
  float x,y;
};

float dist(Point p1,Point p2)
{
     return sqrt((p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y));
}

int compareX(const void *a,const void *b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void *a,const void *b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float bruteforce(Point points[],int n)
{
    float min=100000.0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            if(dist(points[i],points[j])<min) min=dist(points[i],points[j]);
    }
    return min;
}

float min(float x, float y)
{
    return (x < y)? x : y;
}

float stripClosest(Point strip[],int size,float d)
{
    float min = d;
    qsort(strip, size, sizeof(Point), compareY);


    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

float closestPoint(Point points[],int n)
{
    if(n<=3)
        return bruteforce(points,n);

    int mid=n/2;
    Point midPoint=points[mid];

    float dl=closestPoint(points,mid);
    float dr=closestPoint(points+mid,n-mid);

    float d=min(dl,dr);

    Point strip[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(abs(points[i].x-midPoint.x)<d)
        {
            strip[j]=points[i];
            j++;
        }
    }

    return min(d,stripClosest(strip,j,d));
}

int main()
{
    int n;
    cout<<"Enter no. of points"<<endl;
    cin>>n;
    Point points[n];
    cout<<"Enter coordinates of points"<<endl;
    for(int i=0;i<n;i++)
    {
      float x,y;
      cin>>x>>y;
      Point temp;
      temp.x=x;
      temp.y=y;
      points[i]=temp;
    }
    qsort(points,n,sizeof(Point),compareX);
    cout<<closestPoint(points,n);
}
