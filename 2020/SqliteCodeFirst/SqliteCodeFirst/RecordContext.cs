using System;
using System.Collections.Generic;
using System.Configuration;
using System.Reflection;
using System.Text;
using Microsoft.EntityFrameworkCore;

namespace SqliteCodeFirst
{
    class RecordContext : DbContext
    {
        public DbSet<Record> Records { get; internal set; } = null!;

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            var connectionString = ConfigurationManager.ConnectionStrings["TestDatabase"].ConnectionString;
            optionsBuilder.UseSqlite(connectionString, options =>
            {
                options.MigrationsAssembly(Assembly.GetExecutingAssembly().FullName);
            });

            base.OnConfiguring(optionsBuilder);
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Record>(entity =>
            {
                //entity.HasKey(x => x.Id);
                //entity.HasIndex(x => x.Name).IsUnique();
                entity.Property(x => x.DateTime).HasDefaultValueSql("CURRENT_TIMESTAMP");
            });

            base.OnModelCreating(modelBuilder);
        }
    }
}
