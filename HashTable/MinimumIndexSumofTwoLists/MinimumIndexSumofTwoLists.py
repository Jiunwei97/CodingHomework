def findRestaurant(list1, list2):
    # Use a dictionary to store indices of list1
    index_map = {restaurant: i for i, restaurant in enumerate(list1)}
    min_index_sum = float('inf')
    result = []

    # Iterate through list2 and calculate index sums
    for j, restaurant in enumerate(list2):
        if restaurant in index_map:
            index_sum = index_map[restaurant] + j
            if index_sum < min_index_sum:
                min_index_sum = index_sum
                result = [restaurant]  # Start a new result list
            elif index_sum == min_index_sum:
                result.append(restaurant)  # Add to the current result list

    return result

# Example usage
list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]
list2 = ["KFC", "Shogun", "Burger King"]
print(findRestaurant(list1, list2))  # Output: ['Shogun']
