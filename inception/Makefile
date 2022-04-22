all:
	@sudo mkdir -p /home/dahpark/data/db
	@sudo mkdir -p /home/dahpark/data/site
	@sudo chmod 777 /etc/hosts
	@sudo sed -i 's/localhost/dahpark.42.fr/g' /etc/hosts
	@cd srcs && docker-compose up -d
up:
	@cd srcs && docker-compose up -d
down:
	@cd srcs && docker-compose down
fclean:
	@cd srcs && docker-compose down
	@docker system prune --all --force
	@docker volume ls -qf dangling=true | xargs -r docker volume rm
	@sudo rm -rf /home/dahpark/data
	@sudo sed -i 's/dahpark.42.fr/localhost/g' /etc/hosts
