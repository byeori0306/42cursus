all:
	@mkdir -p ~/Desktop/dahpark/data/db
	@mkdir -p ~/Desktop/dahpark/data/site
	@sudo chmod 777 /etc/hosts
	@sudo sed -i '' 's/localhost/dahpark.42.fr/' /etc/hosts
	@cd srcs && docker-compose up -d
up:
	@cd srcs && docker-compose up -d
down:
	@cd srcs && docker-compose down
fclean:
	@cd srcs && docker-compose down
	@docker system prune --all --force
	@docker volume rm srcs_wordpress_data
	@docker volume rm srcs_mariadb_data
	@rm -rf ~/Desktop/dahpark/data/db
	@rm -rf ~/Desktop/dahpark/data/site
