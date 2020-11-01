#include "TypeSort.h"

void swap(int& xp, int& yp) {
	int temp = xp;
	xp = yp;
	yp = temp;
}

void SelectionSort(int* arr, int n) {
	
	// Reference https://www.geeksforgeeks.org/selection-sort/
	int i, j, min_pos;
	// Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
	for (i = 0; i < n - 1; i++) {
		// Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_pos])
				min_pos = j;

		// Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
		swap(arr[min_pos], arr[i]);
	}
}

void InsertionSort(int* arr, int n) {
	// Reference source: https://www.geeksforgeeks.org/insertion-sort/

	int i, key, j;

	// lặp từ vị trí 1 trở đi vì vị trí đầu tiên thì chắc chắn nó đã được sắp xếp (vì chỉ có 1 phần tử nên được sắp xếp)
	for (i = 1; i < n; i++) {
		// key là giá trị tại vị trí hiện tại
		key = arr[i];
		j = i - 1;

		// cứ mỗi vòng lặp thì những giá trị nào lớn hơn key sẽ bị dời về phía sau 
		// và sau nhiều vòng lặp, cứ tiếp tục dời đến khi nào gặp số bé hơn key , hoặc là bằng key thì chèn key vào vị trí trước đó
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int binarySearch(int a[], int item, int low, int high) {
	
	// điều kiện dừng thứ nhất, tức là không thấy phần tử trong mảng, thường tỉ lệ xảy ra sẽ nhiều hơn 
	// lúc này thì cái dãy cần tìm chỉ còn một phần tử, nếu item lớn hơn phần tử đó thì item đứng sau ("low +1"), còn không thì đứng tại "low"
	// Lưu ý là item sẽ không đứng ở "low -1", vì trong thuật toán chèn, ta dịch chuyển những phần tử "từ vị trí tìm được trở về sau"
	if (low >= high)
		return (item > a[low]) ? (low + 1) : low ;

	int mid = (low + high) / 2;

	// đối với trường hợp này thì trả về  mid cũng được	, đây là điều kiện dừng thứ 2
	// Lưu ý là item sẽ không đứng ở "mid -1", vì trong thuật toán chèn, ta dịch chuyển những phần tử "từ vị trí tìm được trở về sau"

	if (item == a[mid])
		return mid ;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	else
		return binarySearch(a, item, low, mid - 1);
}

void Binary_InsertionSort(int* arr, int n) {

	// Reference source: https://www.geeksforgeeks.org/binary-insertion-sort/
	int i, pos, end_sorted_list, selected;

	// cho for chạy từ i = 1 (xem như i = 0 là đã sắp xếp) đến n-1
	for (i = 1; i < n; i++) {
		// lấy vị trí trước i, cũng chính là vị trí cuối của dãy đã sắp xếp
		end_sorted_list = i - 1;
		// lấy phần tử cần tìm vị trí
		selected = arr[i];

		// Tìm ra vị trí của phần tử cần chèn bằng tìm kiếm nhị phân, tìm từ vị trí 0 đến end_sorted_list
		pos = binarySearch(arr, selected, 0, end_sorted_list);

		// Sau đó ta di chuyển các phần từ vị trí đó ra sau 1 đơn vị 
		while (end_sorted_list >= pos) {
			arr[end_sorted_list + 1] = arr[end_sorted_list];
			end_sorted_list--;
		}
		// sau khi di chuyển thì chèn phần tử đó vào , bởi vì sau đó end_sorted_list-- nên ta phải để là end_sorted_list + 1
		arr[end_sorted_list + 1] = selected;
	}
}

void BubbleSort(int* arr, int n) {
	// Refernce: https://nguyenvanhieu.vn/thuat-toan-sap-xep-bubble-sort/

	int i, j;
	bool check_swap = false;
	// bởi vì chúng ta so sánh phần tử i với i+1 nên chỉ càn lặp từ 0 đến n-2 (gần cuối)
	// cách khác: cho i chạy từ n-2 về 1
	// chỉ cần về 1 thôi vì i chạy tới 1, j chạy từ 0 đến 1 và hoán vị là xong
	for (i = n - 2; i >= 1; i--) {
		// i phần tử cuối cùng đã được sắp xếp
		check_swap = false;
		// cho j chạy từ đâu đến chỗ i
		// chỗ này nảy sinh 1 vấn đề đó là <= và <
		// https://stackoverflow.com/questions/12135518/is-faster-than
		for (j = 0; j <= i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				check_swap = true; // Kiểm tra lần lặp này có swap không
			}
		}
		// Nếu không có swap nào được thực hiện => mảng đã sắp xếp. Không cần lặp thêm
		// Tuy  nhiên chỗ này có nhược điểm đó là giả sử như có 1 cặp đầu tiên  cho swap = true, như vậy thì nó vẫn so sánh rất nhiều lần -> phí time
		if (check_swap == false) {
			break;
		}
	}
}

void ShakerSort(int* arr, int n) {
	// Reference source: https://www.geeksforgeeks.org/cocktail-sort/

	// Biên trái và biên phải
	int Left = 0;
	int Right = n - 1;

	// bien kiem tra swap
	bool checkSwap = false;

	// điều kiện dừng của vòng lăp là khi nào left chạm right , tức là left = right
	while (Left < Right) {

		// chạy vòng for từ left đến right - 1 để đẩy phần tử lớn về biên phải
		for (int i = Left; i <= Right - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				checkSwap = true;
			}
		}

		// không có phần tử nào bị di chuyển, tức là mảng đã được sắp xếp 
		if (checkSwap == false)
			break;
		// thiết lập lại checkSwap 
		checkSwap = false;

		// sau đó giảm biên phải đi 1 đơn vị
		Right--;


		// chạy vòng for ngược lại từ biên phải về "gần biên trái" để đẩy phần tử bé về biên trái
		for (int i = Right - 1; i >= Left +1 ; i--) {
			if (arr[i] < arr[i - 1]) {
				swap(arr[i], arr[i - 1]);
				checkSwap = true;
			}
		}

		if (checkSwap == false)
			break;

		// tăng biên trái lên 1 đơn vị
		Left ++;
	}
	

	/* int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right) {
		for (int i = Left; i < Right; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--) {
			if (arr[i] < arr[i - 1]) {
				swap(arr[i], arr[i - 1]);
				k = i;
			}
		}
		Left = k;
	}*/
}


void ShellSort(int* arr, int n) {
	// Sọurce: https://www.geeksforgeeks.org/shellsort/

	// Start with a big gap, then reduce the gap 
	for (int gap = n / 2; gap > 0; gap /= 2) {
		// Do a gapped insertion sort for this gap size. 
		// The first gap elements a[0..gap-1] are already in gapped order 
		// keep adding one more element until the entire array is 
		// gap sorted  
		for (int i = gap; i < n; i += 1) {
			// add a[i] to the elements that have been gap sorted 
			// save a[i] in temp and make a hole at position i 
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct  
			// location for a[i] is found 
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location 
			arr[j] = temp;
		}
	}
}

// ------------------------HEAP SORT--------------------------

// Reference source:https://drive.google.com/drive/folders/1OtX7ETex4DvSMCWuuKJLRX1Vt8hMkR7E
// Tham khảo từ code trong slide của thây Lê Chí Nam

void HeapRebuild(int pos, int* Arr, int n) {
	int k = pos;
	int v = Arr[k];
	bool isHeap = false;
	int j;
	while (isHeap == false && 2 * k + 1 < n) {
		// xét vị trí 2k +1
		j = 2 * k + 1;

		// nếu Arr[2k +1 ] < Arr[2k +2] thì ta lấy vị trí 2k +2 (lấy cái nào lớn hơn) 
		if (j < n - 1 && Arr[j] < Arr[j + 1]) {
			j++;
		}
		if (v >= Arr[j]) {
			isHeap = true;
		} else {
			swap(Arr[k], Arr[j]);
			// khi  mình swap thì có thể nó sẽ không còn giữ được cái tính chất heap ở những phần tử
			// mà mình swap nữa nên mình phải rebuild lai ở những vị trí đó
			k = j;
		}
	}
}

void HeapConstruction(int* Arr, int n) {
	int start = (n - 1) / 2;
	while (start >= 0) {
		HeapRebuild(start, Arr, n);
		start--;
	}
}

void HeapSort(int* arr, int n) {
	HeapConstruction(arr, n);
	int r = n - 1;
	while (r > 0) {
		swap(arr[0], arr[r]);
		HeapRebuild(0, arr, r);
		r = r - 1;
	}
}

// ------------------------MERGE SORT--------------------------

// Reference source:https://www.geeksforgeeks.org/merge-sort/

// hàm merge để nối 2 mảng đã được sắp xếp và liên tiếp nhau lại với nhau
// start_left là chỉ số đầu của mảng trái 
// n1 là số lượng phần tử mảng bên trái
// n2 là số lượng phần tử mảng bên phải
void merge(int arr[], int start_left, int n1, int n2) {

	int i, j, k;

	// tạo ra 2 mảng tạm 
	int* Left_temp = new int[n1];
	int* Right_temp = new int[n2];

	// Copy dữ liệu sang các mảng tạm
	for (i = 0; i < n1; i++)
		Left_temp[i] = arr[start_left + i];
	for (j = 0; j < n2; j++)
		Right_temp[j] = arr[start_left + n1 + j];

	// Gộp hai mảng tạm vừa rồi vào mảng arr
	// Khi mà vòng lặp dừng thì cũng có nghĩa là có thể đã đưa các phần tử của mảng left hoặc mảng right vô hết
	i = 0;
	j = 0;
	k = start_left;
	while (i < n1 && j < n2) {
		if (Left_temp[i] <= Right_temp[j]) {
			arr[start_left] = Left_temp[i];
			i++;
		} else {
			arr[start_left] = Right_temp[j];
			j++;
		}
		start_left++;
	}

	// Copy các phần tử còn lại của mảng Left_temp vào arr  
	while (i < n1) {
		arr[start_left] = Left_temp[i];
		i++;
		start_left++;
	}

	// Copy các phần tử còn lại của mảng Right_temp vào arr  
	while (j < n2) {
		arr[start_left] = Right_temp[j];
		j++;
		start_left++;
	}
	delete Left_temp;
	delete Right_temp;
}

void merge_sort(int arr[], int left, int right) {
	if (left < right) {
		// lấy vị trí ở giữa
		int mid = left + (right - left) / 2;

		// chia làm 2 phần và merge sort nó
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);

		// sau khi merge sort xong thì nối nó lại 
		merge(arr, left, mid -left + 1 , right -mid);
	}
}

void MergeSort(int* arr, int n) {
	merge_sort(arr, 0, n - 1);
}

// ------------------------QUICK SORT--------------------------

// Reference source:https://drive.google.com/drive/folders/1OtX7ETex4DvSMCWuuKJLRX1Vt8hMkR7E
// Tham khảo từ code trong slide của thây Lê Chí Nam

// Hàm phân đoạn dựa vào pivot, ở đây ta lấy pivot là phần tử ở giữa, ngoài ra ta còn có thể lấy pivot là phần tử ở cuối hoặc là phần tử đầu  
int partition(int *arr, int start, int end) {
	
	int pivot;
	pivot = arr[(end + start) / 2];

	// biên trái 
	int left = start;
	// biên phải, end - 1 là vì cái end mình dùng làm pivot rồi
	int right = end;
	
	// khi mà vòng lặp dừng thì mảng đã được phân đoạn thành 2 phần, phần trái nhỏ hơn pivot và phần sau lớn hơn pivot
	while (true) {
		
		// duyệt từ đầu đến cuôi, làm như vậy đến khi nào mà gặp phần tử lớn hơn hoặc bằng pivot thì dừng (tiết kiệm phép so sánh)
		while (left <= right && arr[left] < pivot) left++; 
		// tương tự đối với biên phải
		while (right >= left && arr[right] > pivot) right--; 
		
		// nếu như left >= right, tức là trừ phần tử cuối ra thì mảng đã được phân đoạn thành 2 phần, phần trái nhỏ hơn pivot và phần sau lớn hơn pivot
		if (left >= right) break; 
		// nếu như tới được đây thì có nghĩa là phần tử left >= pivot, còn right <= pivot, sau đó đổi chỗ
		swap(arr[left], arr[right]);
		left ++; 
		right --; 

	}

	// sau khi kết thúc vòng lặp thì left sẽ ở vị trí đầu của phần lớn hơn pivot 
	// đổi chỗ phần tử đầu đó với pivot
	swap(arr[left], pivot);
	return left; // Trả về vị trí nơi pivot đứng
}

void quickSort(int arr[], int start, int end ) {
	if (start < end) {
		
		int pivot_pos = partition(arr, start, end);

		quickSort(arr, start, pivot_pos - 1);
		quickSort(arr, pivot_pos + 1, end);
	}
}

void QuickSort(int* arr, int n) {
	quickSort(arr, 0, n - 1);
}

void CountingSort(int* arr, int n) {

	// Reference source: https://nguyenvanhieu.vn/counting-sort/
	int *output = new int[n];
	int max = arr[0];
	int min = arr[0];

	int i;

	// tìm phần tử lớn nhất và phần tử nhỏ nhất trong mảng
	for (i = 1; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}

	int k = max - min + 1; // Kích thước mảng count

	// tạo ra mảng count chứa số lần xuất hiện của các phần tử
	int* count_array = new int[k];
	// Tiền xử lý mảng count, cho tất cả các giá trị bằng 0
	for (i = 0; i < k; i++)
		count_array[i] = 0;
	// Tiến hành đếm số lần xuất hiện các phần tử và cho vào count_array
	for (i = 0; i < n; i++)
		count_array[arr[i] - min]++;

	// Cập nhật lại giá trị của count_array, thay vì chứa số lần xuất hiện thì bây giờ nó sẽ chứa vị trí
	for (i = 1; i < k; i++)
		count_array[i] += count_array[i - 1];

	// Bắt đầu đổ dữ liệu vào out put dựa trên vị trí các phần tử ở count_array
	for (i = 0; i < n; i++) {
		// phải trừ đi cho 1 bởi vì cái này là vị trí của nó nhưng mà tính theo kiểu thứ n
		output[count_array[arr[i] - min] - 1] = arr[i];
		count_array[arr[i] - min]--;
	}

	// copy mảng dữ liệu vào mảng ban đầu
	for (i = 0; i < n; i++)
		arr[i] = output[i];
	delete output;
	delete count_array;
}

void RadixSort(int* arr, int n) {

	// Reference source https://www.geeksforgeeks.org/radix-sort/

	// pass_resulf là mảng chứa các phần tử sau mỗi lần pass
	int* pass_resulf = new int[n];
	int i,  max = arr[0], exp = 1;

	// tìm giá trị lớn nhất trong mảng và lưu vào m, mục đích là để tạo ra một điều kiện dừng cho vòng lặp
	for (i = 0; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}

	// Số lần pass sẽ bằng số chữ số của số lớn nhất
	while (max / exp > 0) {
		int bucket[10] = { 0 };

		// Tiến hành pass và lưu số lượng vào bucket
		// bucket[arr[i] / exp % 10] chính là giá trị một xô trong số 10 xô, giá trị xô này là số lượng chứ không phải phần tử
		for (i = 0; i < n; i++)	
			bucket[arr[i] / exp % 10]++;

		// Chuẩn hóa lại giá trị trong các bucket, chuyển từ số lượng thành vị trí, khá là giống với counting sort
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		
		// tiến hành đổ các phần tử ở mảng arr vào mảng b, ta phải đổ từ cuối về đầu chứ không được đổ từ đầu về cuối
		for (i = n - 1; i >= 0; i--)
			pass_resulf[--bucket[arr[i] / exp % 10]] = arr[i];

		// gán lại mảng ban đầu
		for (i = 0; i < n; i++)
			arr[i] = pass_resulf[i];

		// thay đổi exp lên một nấc cao hơn
		exp *= 10;
	}

	delete pass_resulf;
}

void FlashSort(int* arr, int n) {}


