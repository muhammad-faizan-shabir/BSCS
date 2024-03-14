//Q1
Median(A[],B[],leftA,rightA,leftB,rightB)
{
	if(rightA-leftA+1<=2 and rightB-leftB+1<=2)
	{
		if(rightA - leftA + 1==1 and rightB - leftB + 1==1)
		{
			return (A[leftA] + B[leftB]) / 2;
		}
		else if(rightA - leftA + 1 == 1 and rightB - leftB + 1 == 2)
		{
			temp[1.....3];
			temp[1] = A[leftA];
			temp[2] = B[leftB];
			temp[3] = B[rightB];
			sort(temp, 3);
			return temp[2];
		}
		else if (rightA - leftA + 1 == 2 and rightB - leftB + 1 == 1)
		{
			temp[1....3];
			temp[1] = A[leftA];
			temp[2] = A[rightA];
			temp[3] = B[leftB];
			sort(temp, 3);
			return temp[2];
		}
		else
		{
			temp[1....4];
			temp[1]= A[leftA];
			temp[2]= A[rightA];
			temp[3]= B[leftB];
			temp[4]= B[rightB];
			sort(temp, 4);
			return (temp[2] + temp[3]) / 2;
		}
	}
	else
	{
		midA = (leftA + rightA) / 2;
		midB = (leftB + rightB) / 2;
		medianA = A[midA];
		medianB = B[midB];
		if(medianA==medianB)
		{
			return medianA;
		}
		else if(medianA<medianB)
		{
			return Median(A, B, midA, rightA, leftB, midB);
		}
		else
		{
			return Median(A, B, leftA, midA, midB, rightB);
		}
	}
}

//Q2
findMajorityElement(Arr[],left,right)
{
	if(left==right)
	{
		return Arr[left];
	}
	
	mid = (left + right) / 2;

	leftMajority = findMajorityElement(Arr, left, mid);
	rightMajority = findMajorityElement(Arr, mid + 1, right);

	if(leftMajority==rightMajority)
	{
		return leftMajority;
	}

	leftCount = countFrequency(Arr, left, right, leftMajority);
	rightCount = countFrequency(Arr, left, right, rightMajority);

	if(leftCount>(right-left+1)/2)
	{
		return leftMajority;
	}
	else if (rightCount>(right-left+1)/2)
	{
		return rightMajority;
	}
	else
	{
		return -1;
	}
}

countFrequency(Arr[],left,right,value)
{
	count = 0;
	for(i=left;i<=right;i++)
	{
		if(Arr[i]==value)
		{
			count++;
		}
	}

	return count;
}

//Q3
findRotations(Arr[],left,right)
{
	if(right<left)
	{
		return 0;
	}

	if(right==left)
	{
		return left - 1;
	}

	mid = (left + right) / 2;

	if(mid<right and Arr[mid+1]<Arr[mid])
	{
		return mid + 1 - 1;
	}

	if(mid>low and Arr[mid]<Arr[mid-1])
	{
		return mid - 1;
	}

	if(Arr[right]>Arr[mid])
	{
		return findRotations(Arr,left,mid-1);
	}
	else
	{
		return findRotations(Arr, mid + 1, right);
	}
}

//Q4
DistanceXY(Arr[],N,X,Y) // non-divide and conquer approach
{
	if(X<Y)
	{
		lowerBound = X;
		upperBound = Y;
	}
	else
	{
		lowerBound = Y;
		upperBound = X;
	}
	
	distance = 0;
	for(i=1;i<=N;i++)
	{
		if(Arr[i]>=lowerBound and Arr[i]<=upperBound)
		{
			distance++;
		}
	}

	return distance - 2; // -2 is to exclude the count of boundaries
}

main() //divide and conquer approach
{
	d=DistanceXY(Arr,left,right,X,Y);
	return d - 2; // -2 is to exclude the count of boundaries
}

DistanceXY(Arr[], left,right, X, Y)
{
	if(left<right)
	{
		mid = (left + right) / 2;
		distance = 0;
		distance += DistanceXY(Arr, left, mid, X, Y);
		distance+= DistanceXY(Arr, mid+1, right, X, Y);
		return distance;
	}
	else
	{
		if (X < Y)
		{
			lowerBound = X;
			upperBound = Y;
		}
		else
		{
			lowerBound = Y;
			upperBound = X;
		}

		if(Arr[left]>=lowerBound and Arr[left]<= upperBound)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

//Q5 
findPair(Arr[],left,right,y)
{
	flag = false;
	MergeSort(Arr, left, right); // assuming that merge sort is already implemented

	for(i=left;i<=right and flag==false;i++)
	{
		searchKey = Arr[i] + y;
		flag=BinarySearch(Arr, left + 1, right,searchKey); // binary search function returns index
		                                                   // of the value if found otherwise 0 i.e flase
	}

	return flag;
}

BinarySearch(Arr[],left,right,searchKey)
{
	while(left<=right)
	{
		mid = (left + right) / 2;

		if(Arr[mid]==searchKey)
		{
			return mid;
		}
		else if(Arr[mid]<searchKey)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return 0;
}

//Mid1 Q1
findSubArray(Arr[], left, right, V, K)
{
	nearestCount = 0;
	closestIndex = BinarySearch(Arr, left, right, V); // binary search function returns closest index
	nearestCount++;
	i = closestIndex - 1;
	j = closestIndex + 1;
	while (nearestCount < K and i >= left and j <= right)
	{
		diff1 = AbsDiff(V, Arr[i]);
		diff2 = AbsDiff(V, Arr[j]);
		if (diff1 <= diff2)
		{
			i--;
		}
		else
		{
			j++;
		}
		nearestCount++;
	}

	while(nearestCount<k and i>=left)
	{
		i--;
		nearestCount++;
	}
	
	while(nearestCount<k and j<=right)
	{
		j++;
		nearestCount++;
	}
	start = i++;
	end = j--;

	return(start, end);
}

BinarySearch(Arr[], left, right, searchKey)
{
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (Arr[mid] == searchKey)
		{
			return mid;
		}
		else if (Arr[mid] < searchKey)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return mid;// return the closest index if search fails
}