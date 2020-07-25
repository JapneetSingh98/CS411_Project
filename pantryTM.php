//UI framework

/* when you first get to the website there should be a box that allows a user to type in UserID and Name
   when a user hits "enter" button whatever is in UserID should append to UserIDs array and whatever is in Name should append to UserNames arrays */

/* also when "enter" is hit, the page is replaced with a table that allows the user to enter pantry items
  - text box for item Name, quantity, and a drop down menu for the quanitity type
  - we should add constraints as well, so with quanitity only allow user to type up 2 decimal places or truncate/add decimals as needed
  - when a user hits "add" button those items should be added to pantryItems dict (where UserId and item are the keys)
    this will allow for systematic insert in the queries below */

/* when "finish" is hit, the page will be replaced with the pantry (list of all items and their corresponding attributes)
  (will be done by connecting a sql search * query result to the UI structure)
  - each item in the pantry will have an edit/delete buttons and when clicked will update the pantry as aplicable
  - at the top of the page will be an add button which will take the user back to the add items page
  - at the bottom of the page will be buttons
    "myRecipes": when clicked will replace the page with the recipes that the user has already selected
    "searchRecipes": when clicked will take the user to a table to select searhc criteria */

// for now our search is just going to be a simple query matching criteria conditions, but next we will update it with the advanced functionality
/* when "searchRecipes" is hit there should be two buttons that a user can hit which will bring up two drop down menus:
    - dietary restictions with the lsited restrictions
    - meal type with the listed meal types a user can select
    when "search" is hit the results of those selected should be appended to dietRests array and mealTypes array */

/* when search is hit, the recipe names and Id's that match the criteria will be displayed
  (will be done by connecting a sql search Id, name Query to the UI structure)
  - a user can press on a recipe name to get more details (same as before, conenct UI to SQL query)
  - for each recipe there will be
    "favorite" button: when clicked will add the recipe to the myRecipes
    "cook" button: when clicked will update the pantry contents (for now this functionality won't work, this is for next week



// connect database to mySQL

//below will be the queries that use the arrays from above

// add, delete user accounts
// add, delete, update pantry
// favorite/unfavorite recipes to my recipes
// searching recipe table based on filters
// reccomended recipes (next week)
// alerts on food that is going to expire (next week)
