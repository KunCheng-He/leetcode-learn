class Solution:
    def removeDuplicates(self, nums) -> int:
        while True:
            index = None
            for i in range(len(nums) - 1):
                if nums[i] == nums[i+1]:
                    index = i
                    break
            if index is None:
                return len(nums)
            else:
                while True:
                    nums.pop(index)
                    try:
                        if not nums[index] == nums[index + 1]:
                            break
                    except IndexError:
                        break



if __name__=="__main__":
    nums = [0,0,1,1,1,2,2,3,3,4,4]
    ans = Solution()
    num = ans.removeDuplicates(nums)
    print(num, nums)
