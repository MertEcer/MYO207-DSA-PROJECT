// Selim Mert ECER
// 2420161025
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=WJ1SkNaG46
#include <stdio.h>

#define N 7

void dizi_yazdir(int dizi[], int bas_ind, int son_ind) {
	for (int i = bas_ind; i <= son_ind; i++) {
		printf("%d ", dizi[i]);
	}
}

void takas(int *ap, int *bp) {
	int gecici = *ap;
	*ap = *bp;
	*bp = gecici;
}

int medyan_indis_hesapla(int dizi[], int bas_ind, int son_ind) {
	int orta_ind = (bas_ind + son_ind) / 2;
	int a = dizi[bas_ind], b = dizi[orta_ind], c = dizi[son_ind];
	
	if (((a<c) && (c<b)) || ((b<c) && (c<a))) {
		return son_ind;
	}
	else if (((a<b) && (b<c)) || ((c<b) && (b<a))) {
		return orta_ind;
	}
	else if (((b<a) && (a<c)) || ((c<a) && (a<b))) {
		return bas_ind;
	}
	else {
		return orta_ind;
	}
}

int bolumleme(int dizi[], int bas_ind, int son_ind) {
	int med_ind = medyan_indis_hesapla(dizi, bas_ind, son_ind);
	int pivot = dizi[med_ind];
	int i = bas_ind, j = son_ind;
	
	printf("\n (pivot : %d)", pivot);
	
	while (i <= j) {
		while (dizi[i] < pivot) {
			i++;
		}
		while (dizi[j] > pivot) {
			j--;
		}
		
		if (i <= j) {
			takas(dizi+i, dizi+j);
			i++; 
			j--;
			
			printf("\n");
			dizi_yazdir(dizi, 0, N-1);
		}
	}
	return i; 
}

void hizli_sirala(int dizi[], int bas_ind, int son_ind) {
	if (bas_ind < son_ind) {
		int konum = bolumleme(dizi, bas_ind, son_ind);
		printf(" ----> [ ");
		dizi_yazdir(dizi, bas_ind, konum-1);
		printf("] ve [");
		dizi_yazdir(dizi, konum, son_ind);
		printf("]");
		
		if (bas_ind < konum - 1) {
			hizli_sirala(dizi, bas_ind, konum - 1);
		}
		if (son_ind > konum) {
			hizli_sirala(dizi, konum, son_ind);
		}
	}
}

int ikili_arama(int dizi[], int bas_ind, int son_ind, int aranan) {
	while (bas_ind <= son_ind) {
		int orta_ind = (bas_ind + son_ind) / 2;
		
		if (dizi[orta_ind] == aranan) {
			return orta_ind;
		}
		
		if (dizi[orta_ind] < aranan) {
			bas_ind = orta_ind + 1;
		}
		else {
			son_ind = orta_ind - 1;
		}
	}
	return -1;
}

int main() {
	int A[] = {3, 1, 6, 5, 8, 2, 4};
	int aranan = 5;
	
	printf("\n");
	dizi_yazdir(A, 0, N-1);
	
	hizli_sirala(A, 0, N-1);  
	
	printf("\n");
	dizi_yazdir(A, 0, N-1);	
	
	int sonuc = ikili_arama(A, 0, N-1, aranan);
	
	if (sonuc != -1)
		printf("\n\nAranan sayi %d, %d. indiste bulundu.", aranan, sonuc);
	else
		printf("\n\nSayi bulunamadi.");
	
	return 0;
}
