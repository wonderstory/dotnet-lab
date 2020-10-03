using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Text;

namespace SqliteCodeFirst
{
    public class Record
    {
        [Key]
        public int Id { get; private set; }

        [Required]
        [MaxLength(128)]
        public string Name { get; set; } = null!;

        public DateTime DateTime { get; set; }

        [NotMapped]
        public DateTimeOffset LocalDateTime => DateTime.ToLocalTime();
    }
}
