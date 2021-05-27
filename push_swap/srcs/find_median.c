#include "../push_swap.h"

static void	merge(int arr[], int left, int mid, int right)
{
	int temp[right + 1];
	int i;
	int j;
	int t;

	i = left;
	j = mid + 1;
	t = 0;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			temp[t++] = arr[i++];
		else
			temp[t++] = arr[j++];
	}
	while (i <= mid)
		temp[t++] = arr[i++];
	while (j <= right)
		temp[t++] = arr[j++];
	t--;
	while (t >= 0)
	{
		arr[left+t] = temp[t];
		t--;
	}
}

static void	merge_sort(int arr[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int	find_median(t_list *x, int n)
{
	int arr[n];
	int i;
	t_node *curr;

	curr = x->tail;
	i = n - 1;
	while (i >= 0)
	{
		arr[i] = curr->value;
		curr = curr->prev;
		i--;
	}
	merge_sort(arr, 0, n-1);
	return (arr[n/2]);
}
