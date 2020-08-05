#include<stdio.h>
#include<iostream>
#include <vector>
using namespace std;

struct Recipe {
  int id;
  string name;
  string instructions;
  int prepTime;
  int cookTime;
  int servings;
};
vector<Recipe> Recipes;

//1
Recipes[6].id = 1;
Recipes[6].name = "Chocolate Chip Cookies";
Recipes[6].instructions = "Mix ingredients then form balls and bake on a cookie sheet at 375 for 8-10 minutes until cooked to satisfaction.";
Recipes[6].prepTime = 20;
Recipes[6].cookTime = 10;
Recipes[6].servings = NULL;

//2
Recipes[27].id = 2;
Recipes[27].name = "Whole Wheat Chocolate Chip Banana Pancakes";
Recipes[27].instructions = "Mix ingredients then form balls and bake on a cookie sheet at 375 for 8-10 minutes until cooked to satisfaction.";
Recipes[27].prepTime = 5;
Recipes[27].cookTime = 5;
Recipes[27].servings = 6;

//3
Recipes[4].id = 3;
Recipes[4].name = "Cereal";
Recipes[4].instructions = "Mix all solids in one bowl. All liquids in another. Add solids to liquids. Mix. Put on pan. Add chocolate chips. Flip. ";
Recipes[4].prepTime = 1;
Recipes[4].cookTime = 0;
Recipes[4].servings = 1;

//4
Recipes[24].id = 4;
Recipes[24].name = "veg chili";
Recipes[24].instructions = "1) Put your choice of cereal into a bowl 2) Pour milk over the cereal";
Recipes[24].prepTime = 15;
Recipes[24].cookTime = 10;
Recipes[24].servings = 4;

//5
Recipes[11].id = 5;
Recipes[11].name = "Greek village salad ";
Recipes[11].instructions = "Heat oil in the pan, when it’s hot, add in the minced green chili/jalapeños/chili flakes. After a minute or two, add in the green pepper and celery. Stir occasionally for 4-5 minutes until the vegetables have softened, add in the corn and tomatoes. When adding the tomato paste, make sure to add water to thin it out. Use your judgement, maybe a cup ish? Stir well for another 8-10 minutes, adding in the beans a few minutes in. Then add in the chili flakes, the Italian seasoning, paprika, brown sugar, salt, and basil. Stir often. After the 10 minutes are up, add in more water, so nothing burns while pressure cooking, and then pressure cook on high for 12 or so minutes. Once that’s done, you may have to sauté for a few minutes to get the consistency you would like. Add basil to top.";
Recipes[11].prepTime = 15;
Recipes[11].cookTime = 3;
Recipes[11].servings = 5;

//6
Recipes[18].id = 6;
Recipes[18].name = "Oreo Cookie Cheesecake";
Recipes[18].instructions = "Chop up all ingredients to size of choice, combine in bowl, drizzle over olive oil and oregano, toss, and serve with a side of bread";
Recipes[18].prepTime = 60;
Recipes[18].cookTime = 240;
Recipes[18].servings = 10;

//7
Recipes[21].id = 7;
Recipes[21].name = "Pesto Pasta";
Recipes[21].instructions = "Mix all ingredients. Whisk. Crush oreo cookies. Make cheesecake. Enjoy. ";
Recipes[21].prepTime = 10;
Recipes[21].cookTime = 10;
Recipes[21].servings = 6;

//8
Recipes[1].id = 8;
Recipes[1].name = "15 Minute Spicy Udon Stir Fry";
Recipes[1].instructions = "Toast pine nuts in the oven by preheating the oven at 350 and baking for 5-7 minutes. In a food processor pulse toasted pine nuts, chopped garlic, and Parmesan, then add basil then slowly add oil. Salt to taste, stir into fresh cooked pasta with scoop of pasta water";
Recipes[1].prepTime = 5;
Recipes[1].cookTime = 10;
Recipes[1].servings = 2;

//9
Recipes[5].id = 9;
Recipes[5].name = "Chicken Slime";
Recipes[5].instructions = "1) Prepare your vegetables and set aside. Mix up the sauce by combining all the ingredients in a small bowl. Set aside. If you like, you can fill a large bowl with hot tap water and add udon noodles to the bowl to soak, so they can be separated before adding to the wok This isn't necessary though, as you can add fresh udon noodles directly from the package to the wok. I just find it easier to stir fry them having them separate before the go in to the wok. 2) In a large frying pan or wok, heat oil over medium-high heat until very hot. Add carrots and cook, stirring for a minute or so. Add onions and cook, stirring, until onions are soft and carrots are tender. Add green onion and cook, stirring, for 30 seconds or so. 3) If soaking udon noodles, gently stir to loosen udon noodles and separate, then drain. Add drained noodles (or unsoaked noodles)to the wok and cook, stirring, for 30 seconds or so. (Stir fry a little longer is soaked, to cook off any extra water before adding the sauce). Add sauce and cook for another 30 second, stirring to combine well. Scatter baby spinach over top and cook, stirring constantly, until spinach is wilted. 4) Remove stir fry to a bowl or plate and garnish with sesame seeds, additional sliced green onion and parsley/cilantro.";
Recipes[5].prepTime = 5;
Recipes[5].cookTime = 30;
Recipes[5].servings = 2;

//10
Recipes[7].id = 10;
Recipes[7].name = "Creamy Baked Mac and Cheese";
Recipes[7].instructions = "Season chicken breast liberally with salt, pepper, onion, and garlic powder. Place on baking sheet and bake at 400 degrees fahrenheit for 25 minutes. Place chicken breast into blender along with olive oil (for a low fat version, use chicken broth). Blend until smooth and homogenous. Use as dip, sandwich spread, or post-workout smoothie.";
Recipes[7].prepTime = 20;
Recipes[7].cookTime = 15;
Recipes[7].servings = 8;

//11
Recipes[16].id = 11;
Recipes[16].name = "Nutty Berry Sandwich";
Recipes[16].instructions = "Lather spreads on to a single side of each slice of bread. Combine slices with spread on the inside";
Recipes[16].prepTime = 2;
Recipes[16].cookTime = 4;
Recipes[16].servings = 1;

//12
Recipes[14].id = 12;
Recipes[14].name = "Homemade Granola";
Recipes[14].instructions = "Heat oven to 350 degree F. In a large bowl, mix together Old Fashioned Oats, Sliced Almonds, and Chopped Walnuts. In a smaller bowl, combine Pure Maple Syrup, Vegetable Oil, Ground Cinnamon, Vanilla, & Ground Nutmeg. Drizzle over oat mixture & mix well. Spread evenly in 13 by 9 inch baking pan. Cook for 20min and allow time to cool.";
Recipes[14].prepTime = 10;
Recipes[14].cookTime = 20;
Recipes[14].servings = 8;

//13
Recipes[20].id = 13;
Recipes[20].name = "Peanut Butter and Jelly Sandwich";
Recipes[20].instructions = "Take your 2 slices of white bread and spread the peanut butter and jelly equally on each slice. Then combine the 2 slices together.";
Recipes[20].prepTime = 2;
Recipes[20].cookTime = 0;
Recipes[20].servings = 1;

//14
Recipes[13].id = 14;
Recipes[13].name = "Herby couscous and garlic butter shrimp";
Recipes[13].instructions = "Toast Couscous with a little bit of oil Add 2 cups of water, 2 tbsp of salt and 1 smashed garlic clove Bring to boil, cover the pot, and let it simmer for 10 -12 minutes Take out the garlic clove and save for later Once all the water is absorbed add green onions, 3 tbsp cilantro, and artichoke lemon pesto Set aside couscous For the shrimp mix together butter, remaining cilantro, chopped garlic, and 1 white portion of green onion chopped Place shrimp on foil, drizzle with a little bit of oil, salt and pepper, and lime juice, then smother shrimp with butter mixture Tent the foil and bake for 15 minutes at 350F Serve couscous with shrimp and drizzle on top with the melted butter and juices from shrimp pouch.";
Recipes[13].prepTime = 15;
Recipes[13].cookTime = 15;
Recipes[13].servings = 1;

//15
Recipes[10].id = 15;
Recipes[10].name = "Cucumber Bagels";
Recipes[10].instructions = "cut the cucumbers in half and lay on the cream cheese. season to your liking!";
Recipes[10].prepTime = 0;
Recipes[10].cookTime = 1;
Recipes[10].servings = 1;

//16
Recipes[8].id = 16;
Recipes[8].name = "Crispy Chickpea Tacos";
Recipes[8].instructions = "1. Toss chickpeas in oil and your choice of seasonings. Place on baking sheet and bake in oven at 350 degrees for 20 minutes. 2. In the meantime, dice the bell peppers and onions, finely chop the garlic, and saute on medium-heat with oil and seasonings until softened. 3. To make a quick guacamole, mash up some avocado and mix with a squeeze of lime juice, some chili powder, some diced onion, and salt and pepper. 4. When the chickpeas are almost done, heat up your tortillas. Finely chop the cilantro. 5. Assembly time: top each tortilla with the pepper mixture, the chickpeas, the guac, and a squeeze of lime. Top with cilantro and sour cream if desired. ";
Recipes[8].prepTime = 5;
Recipes[8].cookTime = 20;
Recipes[8].servings = 1;

//17
Recipes[3].id = 17;
Recipes[3].name = "Baked white fish with tomatoes, garlic, parsley and lemon";
Recipes[3].instructions = "-Set your oven for about 400 F - Dry your white fish with paper towels and season with salt and pepper. - Place in the baking dish, add butter, few slices of lemon, a couple of garlic cloves and fresh parsley - Place in the oven for 10 min - Add cherry tomatoes (as many as you like) I love them - Put back in the oven for another 10-15 min until the fish is flaky and tomatoes bursting Enjoy!!!";
Recipes[3].prepTime = 0;
Recipes[3].cookTime = 30;
Recipes[3].servings = 1;

//18
Recipes[19].id = 18;
Recipes[19].name = "Organic basil garlic pistachio pesto";
Recipes[19].instructions = "Combine the basil, garlic, and pistachio Nuts in a food processor and pulse until coarsely chopped. Add 2/3 cup of the oil and process until fully incorporated and smooth. Season with salt and pepper. Mix in the cheese and serve. I don’t put cheese in it since I’m Vegan. I have added violife vegan Parmesan cheese on top at times! Enjoy Mixed in pasta or with warm bread as a dip!";
Recipes[19].prepTime = 0;
Recipes[19].cookTime = 5;
Recipes[19].servings = 3;

//19
Recipes[9].id = 19;
Recipes[9].name = "Crispy Sweet Potato Fries";
Recipes[9].instructions = "1. Peel and cut your sweet potato into long strands that are about 1/4-1/2 inch wide 2. Arrange on a baking sheet 3. Drizzle with olive oil 4. Combine seasonings of your choice into a small bowl, mix and spread evenly on baking sheet 5. Preheat oven to 400 degrees 6. Bake for 15 mins, turn fries over to the other side and bake for another 10 minutes 7. Serve when hot and with any condiments of your choice";
Recipes[9].prepTime = 10;
Recipes[9].cookTime = 30;
Recipes[9].servings = 1;


//20
Recipes[26].id = 20;
Recipes[26].name = "Vegan pancakes";
Recipes[26].instructions = "1. Combine dry ingredients and sift 2. Mix wet ingredients in a small bowl 3. Add wet ingredients to dry ingredients slowly by pouring a little at a time 4. Heat griddle to low-medium and spray cooking oil 5. Scoop 1/4 of batter onto griddle 6. Cook 1-2 minutes on each side";
Recipes[26].prepTime = 0;
Recipes[26].cookTime = 15;
Recipes[26].servings = 2;

//21
Recipes[15].id = 21;
Recipes[15].name = "Mango Smoothie Bowl" ;
Recipes[15].instructions = "Throw your frozen mango and banana into a blender and add a dash of milk. Blend the ingredients together in pulses, slowly adding milk until the chunks disappear and the consistency is like sorbet. Transfer your smoothie to a bowl and add your toppings -- the";
Recipes[15].prepTime = 0;
Recipes[15].cookTime = 10;
Recipes[15].servings = 1;

//22
Recipes[23].id = 22;
Recipes[23].name = "Smoothie on the go";
Recipes[23].instructions = "Put all ingredients in the blender and blend for about 30 seconds. Pour freshly made "Smoothie on the Go" into glass and enjoy";
Recipes[23].prepTime = 0;
Recipes[23].cookTime = 10;
Recipes[23].servings = 1;


//23
Recipes[25].id = 23;
Recipes[25].name = "Vegan Pad Thai";
Recipes[25].instructions = "NOODLES 1. Place the noodles in a large bowl and add boiling water to the bowl. 2. Cover the bowl with a plate and let it sit while preparing the tofu and sauce. 3. After about 20 minutes, drain and add 1 tbsp of sesame oil to the noodles and mix. Optional: you can also boil the noodles like you would normally boil noodles. SAUCE 1. Add all the sauce ingredients to a pan and mix with a whisk on low heat. Once everything is combined you can turn the heat off and let it sit. TOFU/ASSEMBLY 1. Add sesame oil to a pan and add the cubes tofu.  2. Add a sprinkle of salt on the tofu. (You don’t want to add a lot here because the sauce is already salty because of the soy sauce) 3. On medium heat cook the tofu until golden brown on each side. 4. Once golden brown, add the soy sauce to the tofu and mix until the tofu is coated and becomes a darker color. 5. Place the pan with the sauce on medium heat and add in the cooked noodles and tofu. 6. Mix until all the sauce is all over the noodles. 7. Add in the sprouts and sliced carrots and mix once more. 8. Add cilantro, peanuts, and lime juice on top and enjoy!";
Recipes[25].prepTime = 5;
Recipes[25].cookTime = 25;
Recipes[25].servings = 2;


//24
Recipes[2].id = 24;
Recipes[2].name = "A Healthy Apple Crisp!";
Recipes[2].instructions = "Combine and mix all ingredients to make the topping, and add the coconut oil in slowly, preferably with your hands. Place in fridge. Combine all ingredients for the crisp and allow the mixture to soak for about 10 minutes. Place the crisp evenly at the bottom of the pan, and pat the topping onto the apples. Bake the crisp at 350 degrees Fahrenheit, for around 40-55 minutes. Vanilla ice cream is an optional topping to this dessert/snack/breakfast!";
Recipes[2].prepTime = 5;
Recipes[2].cookTime = 40;
Recipes[2].servings = 2;


//25
Recipes[12].id = 25;
Recipes[12].name = "Handvo (savory cakes) ";
Recipes[12].instructions = "chop or shred all greens finely mix with handvo mix above mix in 1 cup yogurt And all the other ingredients and let sit for 4-6 hours before cooking Oil muffin tins, pour batter Into each round and then sprinkle sesame seeds on top. If you don’t have muffin tins, grease a 9x13 or 9x9 pan and pour batter in there to bake. cook at 350 degrees for 40 minutes or until golden brown broil on top rack until brown on top…for about 2-3 minutes. Be careful not to burn. ";
Recipes[12].prepTime = 15;
Recipes[12].cookTime = 40;
Recipes[12].servings = 1;

//26
Recipes[17].id = 26;
Recipes[17].name = "Orange tofu";
Recipes[17].instructions = "Tofu: 1. Wrap the tofu with paper towels, place something heavy on top and leave for about an hour so the water drains out. 2. Cut tofu into bite size pieces. 3. Take a bag or a big bowl add your cut tofu with 2 tbsp of cornstarch and 2 tbsp of olive oil. 4. Shake/mix the bag/bowl and place the tofu evenly on an oven pan and bake it for 400 °F until golden brown. We personally like our tofu to be extra crispy so we kept it in until it‘a golden brownish which about 20-25 minutes. Orange sauce: 1. In a large pan on medium to low heat add 2 cups of vegetable broth or water, 1 cup of orange juice, 2 tbsp of apple cider vinegar, 4-5 tsp of chili paste, grated ginger, sugar, and 4-5 tsp of soy sauce (adjust the amount according to your sweetness and spice level). 2. In a separate bowl add 2 tbsp of cornstarch and 2 tbsp of water. Mix it well together. 3. Then, add the cornstarch mix to pan and stir it consistently until it thickens. 4. Next, add the baked tofu in the sauce pan and mix it well until the tofu is coated with the sauce. 5. Last but not least, you can serve it with rice, tacos or eat by itself!";
Recipes[17].prepTime = 0;
Recipes[17].cookTime = 20;
Recipes[17].servings = 1;

//27
Recipes[22].id = 27;
Recipes[22].name = "Rigatoni with Vodka Sauce (Bon Appetit's recipe)";
Recipes[22].instructions = "Boil and salt water. Peel and finely chop onion. Smash garlic cloves and grate Parmesan Cheese. Sautée olive oil, garlic, and onion for 5-7min over medium heat. Add tomato paste and pepper flakes to onion and garlic. Deglaze with vodka and incorporate, reducing heat to low. Mix heavy cream with 1/4 cup boiling water to preheat it, then add to pan with onion garlic and tomato paste. Stir until sauce thickens. Cook pasta to al dente and then transfer to sauce pan. Mix in more Parmesan cheese, and add more pasta water to thin sauce if necessary. Serve in a bowl, and drizzle with oil / garnish with basil.";
Recipes[22].prepTime = 10;
Recipes[22].cookTime = 15;
Recipes[22].servings = 4;
