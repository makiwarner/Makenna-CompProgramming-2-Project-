# Define the executable and add source files
add_executable(recipe_manager_improved
main.cpp Fridge.cpp Pantry.cpp Recipe.cpp RecipeManager.cpp Ingredient.cpp Storage.cpp)

# Specify the include directory for header files
target_include_directories(recipe_manager_improved PUBLIC ${PROJECT_SOURCE_DIR}/include)
