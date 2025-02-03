data <- read.table("data.txt", header = FALSE)
data_vector <- as.numeric(data$V1)
max_value <- max(data_vector)
breaks_count <- max_value / 5
hist(data_vector, main = "Histogram of Data", xlab = "Values", ylab = "Frequency", col = "blue", border = "black" , xlim = c(0 , 400) , breaks = breaks_count)
cat("mean is :" , mean(data_vector) , "\n")
cat("variance is :" , var(data_vector))
