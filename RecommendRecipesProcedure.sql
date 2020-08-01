DELIMITER $$
CREATE PROCEDURE RecommendRecipes( IN userID_input VARCHAR(50))
BEGIN
    DECLARE x  INT DEFAULT 0;
    DECLARE userID varchar(50);
    DECLARE recipeCnt INT DEFAULT 0;
    DECLARE numSimilar INT DEFAULT 0;
    DECLARE recipeID INT DEFAULT 0;
    DECLARE recipeName varchar(255);

    SET userID = userID_input;
    SELECT count(ID) INTO recipeCnt FROM Recipe;

    CREATE TEMPORARY TABLE IF NOT EXISTS RecommendedRecipesTable (UserID varchar(50), RecipeID INT, RecipeName varchar(255), NumSimilar INT,
                                                                  PRIMARY KEY(UserID, RecipeID));
    SET x = 1;
	loop_label:  LOOP
		IF  x > recipeCnt THEN
			LEAVE  loop_label;
		END IF;
        SELECT ID, Name, count(*) INTO recipeID, recipeName, numSimilar
        	FROM Ingredients
            WHERE Name IN (SELECT Name FROM Pantry WHERE UserID = userID) AND ID = x;
        IF recipeID IS NOT NULL
           THEN INSERT IGNORE INTO RecommendedRecipesTable VALUES (userID, recipeID, recipeName, numSimilar);
        END IF;
        SET  x = x + 1;
	END LOOP;

    SELECT RecipeID, RecipeName FROM RecommendedRecipesTable WHERE UserID = userID
    ORDER BY NumSimilar DESC
    LIMIT 3;
END$$
