.PHONY: clean All

All:
	@echo "----------Building project:[ LearnCArrays - Debug ]----------"
	@cd "LearnCArrays" && "$(MAKE)" -f  "LearnCArrays.mk"
clean:
	@echo "----------Cleaning project:[ LearnCArrays - Debug ]----------"
	@cd "LearnCArrays" && "$(MAKE)" -f  "LearnCArrays.mk" clean
