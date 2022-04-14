all:
	@sudo chmod 777 /etc/hosts
	@sudo sed -i '' 's/localhost/dahpark.42.fr/' /etc/hosts
	@cd srcs && docker-compose up -d
up:
	@cd srcs && docker-compose up -d
down:
	@cd srcs && docker-compose down
fclean:
	@cd srcs && docker-compose down
	@docker image prune -a -f
	@docker network prune -f
