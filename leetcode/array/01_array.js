var removeDuplicates = function(nums){
	for(let i = 0; i < nums.length; ++i){
		let value = nums[i];
		for(let j = i + 1; j < nums.length; ++j){
			if(value === nums[j]){
				nums.splice(j, 1);
				j--;
			}
		}
	}
	return nums.length;
}
console.log(removeDuplicates([1,1,2]));
console.log(removeDuplicates([0,0,1,1,1,2,2,3,3,4]));
