(function ($) {
    Drupal.behaviors.AppBehavior = {
        attach: function (context, settings) {
            $(".table-list-wrapper a.action").click(function () {
                $(".loading").show();
                var id = $(this).attr('data');
                $.ajax({
                    url: "/ajax/app/temp/order/" + id
                })
                    .done(function (data) {
                        window.location.reload();
                    });
            });

            //remove item temp

            $(".table-list-wrapper a.delete-item").each(function(){
                $(this).click(function () {
                    var id = $(this).attr('data');
                    $.ajax({
                        url: "/ajax/app/delete/order-item/" + id
                    })
                        .done(function (data) {
                            $("#cook-table-wrapper").replaceWith(data);
                            Drupal.attachBehaviors('#cook-table-wrapper');
                        });

                });
            });
            //reload when close modal
            $(".ctools-modal-content .modal-header a.close").click(function(){
                window.location.reload();
            });

            //cancel table
            $(".table-list-wrapper a.cancel-table").each(function(){
               $(this).click(function(){
                   $(".loading").show();
                   var id = $(this).attr('data');
                   $.ajax({
                       url: "/ajax/app/delete/order/" + id
                   })
                       .done(function (data) {
                           window.location.reload();
                       });
               });
            });
             $("a.print-bill").click(function(){
                 var id = $(this).attr('data');
                 var URL = "/app/print/"+id;
                  window.open(URL);
             });




        }
    };

}(jQuery));
