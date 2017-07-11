#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	int * bits, * kontrol, kontr_sum = 0, j = 0, k = 1, m, l = 0;
	double f;
	string sent;
	cout << "Vvedite kodovyiy kombinaciiy:" << endl;
	cin >> sent;
	m = sent.size();
	while (pow(2.0, k) - k <= m)
		++k;
	bits = new int [m + k + 1];
	for (int i = 0; i < m + k + 1; ++i)
		bits[i] = 0;
	for (int i = 0; i < m + k; ++i)
		if ((f = log((double)i + 1.0) / log(2.0)) != (int)f)
			if (sent[l++] == '1')
				bits[i] = 1;
			else
				bits[i] = 0;
	for (int i = 0; i < m + k + 1; ++i)
		cout << bits[i];
	cout << endl;
	for (int i = 1; i <= m + k; ++i)
		if ((f = log((double)i) / log(2.0)) == (int)f)
			for (int j = i - 1; j < m + k; j += i)
			{
				int c = 0;
				while (c++ < i && j < m + k)
					bits[i - 1] ^= bits[j++];
			}
	for (int i = 0; i < m + k; ++i)
		bits[m + k] ^= bits[i];
	cout << "Kod Hemminga:" << endl;
	for (int i = 0; i < m + k + 1; ++i)
		cout << bits[i];
	cout << endl;
	cout << "Vvedite priniatyiy kodovyiy kombinaciiy:" << endl;
	cin >> sent;
	m = sent.size();
	k = 1; l = 0;
	while (pow(2.0, k) < m)
		++k;
	m -= k + 1;
	bits = new int[m + k + 1];
	kontrol = new int[k];
	for (int i = 0; i < m + k + 1; ++i)
		if (sent[i] == '1')
			bits[i] = 1;
		else
			bits[i] = 0;
	for (int i = 1; i <= m + k; ++i)
		if ((f = log((double)i) / log(2.0)) == (int)f)
		{
			kontrol[l] = 0;
			for (int j = i - 1; j < m + k; j += i)
			{
				int c = 0;
				while (c++ < i && j < m + k)
					kontrol[l] ^= bits[j++];
			}
			++l;
		}
	for (int i = 0; i < m + k + 1; ++i)
		kontr_sum ^= bits[i];
	int sum = 0;
	for (int i = 0; i < k; ++i)
		sum += kontrol[i];
	if (sum == 0 && kontr_sum == 0)
		cout << "V kodovom slove net oshubok";
	else
	if (sum != 0 && kontr_sum == 0)
		cout << "V kodovom slove dvoinaia oshubka";
	else
	if (sum == 0 && kontr_sum == 1)
	{
		cout << "V kodovom slove oshubka v razriade dvoinogo kontrolia" << endl;
		bits[m + k] ^= 1;
		for (int i = 0; i < m + k + 1; ++i)
			cout << bits[i];
		cout << endl;
	}
	else
	if (sum != 0 && kontr_sum == 1)
	{
		sum = 0;
		for (int i = 0; i < k; ++i)
			if (kontrol[i] == 1)
				sum += pow(2.0, i);
		bits[sum - 1] ^= 1;
		cout << "V kodovom slove oshubka v " << sum << " razriade" << endl;
		for (int i = 0; i < m + k + 1; ++i)
			cout << bits[i];
		cout << endl;
	}
	return 0;
}