//Ентропия
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

main()
{	unsigned char c; 
	char name[256];
	long k[256];
	int i, sum=0,a=0;
	double ent=0;
	FILE *file;
		
	cout<<"Input the filename: ";
	cin>>name;
	file=fopen(name,"rb");
	
	for (i=0;i<256;i++)
		k[i]=0;
	while (!feof(file))
	{	c=getc(file);
		sum++;
		k[c]++;
	}
	fclose(file);
	file=fopen("out.txt","w");
	
	for (i=0;i<256;i++)
		if (k[i])
		{	fprintf(file, "%d %d \n",i,k[i]);
			ent+=double(k[i])/sum*log(double(k[i])/sum)/log(2);	
			a++;
		}
	fprintf(file, "Alphabet= %d \n",a);
	fprintf(file, "Symbol count= %d \n",sum);
	fprintf(file, "Entropy= %f \n",-ent);
		
	fclose(file);
	return 0;
}
